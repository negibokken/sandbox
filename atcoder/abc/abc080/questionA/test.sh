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
cat << EOF | try 119
7 17 120
EOF

## test case 2
cat << EOF | try 100
5 20 100
EOF

## test case 2
cat << EOF | try 100
6 18 100
EOF
