#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 2
4 3
2 3 1 4
EOF

## test case 2
cat << EOF | try 1
3 3
1 2 3
EOF

## test case 2
cat << EOF | try 4
8 3
7 3 1 8 4 6 2 5
EOF

## test case 2
cat << EOF | try 2
3 2
1 2 3
EOF

## test case 2
cat << EOF | try 2
3 2
3 2 1
EOF

## test case 2
cat << EOF | try 4
5 2
5 4 1 2 3
EOF

## test case 2
cat << EOF | try 7
8 2
6 5 4 1 2 3 7 8
EOF
