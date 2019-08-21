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
cat << EOF | try 9
3 2
EOF

## test case 2
cat << EOF | try 1
5 3
EOF

## test case 3
cat << EOF | try 27
31415 9265
EOF

## test case 4
cat << EOF | try 114191
35897 932
EOF
