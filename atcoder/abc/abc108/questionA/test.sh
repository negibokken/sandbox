#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 2
3
EOF

## test case 2
cat << EOF | try 9
6
EOF

## test case 2
cat << EOF | try 30
11
EOF

## test case 2
cat << EOF | try 625
50
EOF
