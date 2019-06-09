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
cat << EOF | try 0
3
1 2 3
EOF

## test case 2
cat << EOF | try 2
4
1 3 1 1
EOF

## test case 2
cat << EOF | try 2
8
27 23 76 2 3 5 62 52
EOF
