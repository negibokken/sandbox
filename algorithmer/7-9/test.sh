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
cat << EOF | try 19
6
10 3 2 5 7 8
EOF

## test case 2
cat << EOF | try 15
2
11 15
EOF

## test case 2
cat << EOF | try 21
7
7 7 7 7 7 7 7
EOF

## test case 2
cat << EOF | try 16
10
1 2 3 4 5 1 2 3 4 5
EOF
