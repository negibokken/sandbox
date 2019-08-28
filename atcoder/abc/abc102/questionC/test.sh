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
5
2 2 3 5 5
EOF

## test case 1
cat << EOF | try 6
3
4 8 12
EOF

## test case 2
cat << EOF | try 0
9
1 2 3 4 5 6 7 8 9
EOF

## test case 2
cat << EOF | try 18
6
6 5 4 3 2 1
EOF

## test case 2
cat << EOF | try 6
7
1 1 1 1 2 3 4
EOF
