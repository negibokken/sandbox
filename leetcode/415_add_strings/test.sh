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
cat << EOF | try 59
24 35
EOF

## test case 2
cat << EOF | try 44
19 25
EOF

## test case 2
cat << EOF | try 124
99 25
EOF

## test case 2
cat << EOF | try 125
100 25
EOF

## test case 2
cat << EOF | try 108
9 99
EOF
