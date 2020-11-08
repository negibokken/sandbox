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
cat << EOF | try 3
00000000000000000000000000001011
EOF

## test case 2
cat << EOF | try 1
00000000000000000000000010000000
EOF

## test case 2
cat << EOF | try 31
11111111111111111111111111111101
EOF
