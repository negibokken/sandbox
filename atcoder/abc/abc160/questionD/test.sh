#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo $actual`
  expected=`echo $expected`

  if [ "$actual" = "$expected" ]; then
    # echo "$input => $actual"
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 5 4 1 0
5 2 4
EOF

## test case 2
cat << EOF | try 3 0
3 1 3
EOF

## test case 2
cat << EOF | try 7 8 4 2 0 0
7 3 7
EOF

## test case 2
cat << EOF | try 10 12 10 8 4 1 0 0 0
10 4 8
EOF
