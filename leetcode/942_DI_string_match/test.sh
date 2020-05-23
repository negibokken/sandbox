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
cat << EOF | try 0 4 1 3 2
IDID
EOF

## test case 2
cat << EOF | try 0 1 2 3
III
EOF

## test case 2
cat << EOF | try 3 2 0 1
DDI
EOF
