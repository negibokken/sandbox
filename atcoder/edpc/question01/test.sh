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
cat << EOF | try 30
4
10 30 40 20
EOF

## test case 2
cat << EOF | try 0
2
10 10
EOF

## test case 2
cat << EOF | try 40
6
30 10 60 10 60 50
EOF
