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
cat << EOF | try 4
7
EOF

## test case 2
cat << EOF | try 32
32
EOF

## test case 2
cat << EOF | try 1
1
EOF

## test case 2
cat << EOF | try 64
100
EOF
