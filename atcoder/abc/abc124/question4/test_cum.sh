#!/bin/bash

try() {
  expected="$1"
  input=`cat -`

  actual=`echo $input | ./main_cum`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 4
5 1
00010
EOF

## test case 2
cat << EOF | try 8
14 2
11101010110011
EOF

# 11101010110011

## test case 3
cat << EOF | try 1
1 1
1
EOF
