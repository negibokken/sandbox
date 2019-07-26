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
4
1 2 2 1
EOF

## test case 2
cat << EOF | try 5
5
3 1 2 3 1
EOF

## test case 3
cat << EOF | try 221
8
4 23 75 0 23 96 50 100
EOF

## test case 3
cat << EOF | try 4
8
1 0 1 0 1 0 1 1
EOF

## test case 3
cat << EOF | try 3
8
0 0 1 0 1 0 1 1
EOF
