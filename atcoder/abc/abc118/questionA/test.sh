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
cat << EOF | try 16
4 12
EOF

## test case 2
cat << EOF | try 12
8 20
EOF

## test case 3
cat << EOF | try 2
1 1
EOF
