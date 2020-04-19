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
cat << EOF | try 2 2 0 0 0
5
1 1 2 2
EOF

## test case 2
cat << EOF | try 9 0 0 0 0 0 0 0 0 0
10
1 1 1 1 1 1 1 1 1
EOF

## test case 2
cat << EOF | try 1 1 1 1 1 1 0
7
1 2 3 4 5 6
EOF
