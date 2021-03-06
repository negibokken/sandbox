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
cat << EOF | try 1
6 4 3
EOF

## test case 2
cat << EOF | try 4
8 3 9
EOF

## test case 2
cat << EOF | try 0
12 3 7
EOF
