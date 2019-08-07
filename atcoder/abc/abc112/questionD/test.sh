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
3 14
EOF

## test case 2
cat << EOF | try 3
10 123
EOF

## test case 2
cat << EOF | try 10000
100000 1000000000
EOF
