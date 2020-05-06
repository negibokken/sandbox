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
6
1 1 4 2 1 3
EOF

## test case 2
cat << EOF | try 5
5
5 1 2 3 4
EOF

## test case 2
cat << EOF | try 0
5
1 2 3 4 5
EOF
