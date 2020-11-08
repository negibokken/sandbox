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
cat << EOF | try 15
3
10 15 20
EOF

## test case 2
cat << EOF | try 6
10
1 100 1 1 1 100 1 1 100 1
EOF

## test case 2
cat << EOF | try 0
4
0 0 0 0
EOF
