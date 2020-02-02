#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

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
cat << EOF | try 5
QWERTYASDFZXCV
EOF

## test case 2
cat << EOF | try 4
ZABCZ
EOF

## test case 2
cat << EOF | try 12
HASFJGHOGAKZZFEGA
EOF
