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
8 3 4
2 2 2 2 5 5 5 8
EOF

## test case 2
cat << EOF | try 5
5 1 0
1 1 1 1 1
EOF

## test case 2
cat << EOF | try 6
10 3 5
11 13 17 23 29 31 7 5 2 3
EOF
