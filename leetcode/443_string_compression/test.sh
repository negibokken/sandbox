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
cat << EOF | try 6
7
a a b b c c c
EOF

## test case 2
cat << EOF | try 1
1
a
EOF

## test case 2
cat << EOF | try 4
13
a b b b b b b b b b b b b
EOF
