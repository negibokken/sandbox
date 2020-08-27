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
cat << EOF | try 32
7 7 15
10 5 15 3 7 -1 18
EOF

## test case 2
cat << EOF | try 23
10 6 10
10 5 15 3 7 13 18 1 -1 6
EOF
