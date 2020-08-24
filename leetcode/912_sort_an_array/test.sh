#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  expected=`echo "$expected"`

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
cat << EOF | try 1 3 3 3 4 5 6
7
6 5 3 1 3 4 3
EOF

## test case 2
cat << EOF | try 2 3 3 4
4
3 4 3 2
EOF

## test case 2
cat << EOF | try 1 2 3 5
4
5 2 3 1
EOF

## test case 2
cat << EOF | try 0 0 1 1 2 5
6
5 1 1 2 0 0
EOF
