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
cat << EOF | try 100
30 100
EOF

## test case 2
cat << EOF | try 50
12 100
EOF

## test case 2
cat << EOF | try 0
0 100
EOF
