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
cat << EOF | try 3
13 3 1
EOF

## test case 2
cat << EOF | try 2
12 3 1
EOF

## test case 2
cat << EOF | try 49999
100000 1 1
EOF

## test case 2
cat << EOF | try 110
64146 123 456
EOF

## test case 2
cat << EOF | try 109
64145 123 456
EOF
