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
cat << EOF | try 0.48148148148148148148
3 2
EOF

## test case 2
cat << EOF | try 0.25925925925925925926
3 1
EOF

## test case 2
cat << EOF | try 0.00147697396984624371
765 573
EOF
