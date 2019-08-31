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
cat << EOF | try 3
3
5 2 4
EOF

## test case 2
cat << EOF | try 0
4
631 577 243 199
EOF

## test case 2
cat << EOF | try 39
10
2184 2126 1721 1800 1024 2528 3360 1945 1280 1776
EOF
