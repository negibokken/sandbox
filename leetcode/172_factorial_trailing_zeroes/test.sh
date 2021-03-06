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
cat << EOF | try 0
3
EOF

## test case 2
cat << EOF | try 1
5
EOF

## test case 2
cat << EOF | try 0
0
EOF

## test case 2
cat << EOF | try 1983
7945
EOF
