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
cat << EOF | try 4
4 8
3 6 7 11
EOF

## test case 2
cat << EOF | try 30
5 5
30
EOF

## test case 2
cat << EOF | try 23
5 6
30 11 23 4 20
EOF
