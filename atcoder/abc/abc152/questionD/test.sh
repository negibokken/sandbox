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
cat << EOF | try 17
25
EOF

## test case 1
cat << EOF | try 1
1
EOF

## test case 2
cat << EOF | try 108
100
EOF

## test case 2
cat << EOF | try 40812
2020
EOF

## test case 2
cat << EOF | try 400000008
200000
EOF
