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
cat << EOF | try 2
10
ZABCDBABCQ
EOF

## test case 2
cat << EOF | try 0
19
THREEONEFOURONEFIVE
EOF

## test case 2
cat << EOF | try 5
33
ABCCABCBABCCABACBCBBABCBCBCBCABCB
EOF
