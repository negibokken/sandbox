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
cat << EOF | try 1
A
EOF

## test case 2
cat << EOF | try 28
AB
EOF

## test case 2
cat << EOF | try 27
AA
EOF

## test case 2
cat << EOF | try 701
ZY
EOF

cat << EOF | try 0
CFDGSXM
EOF
