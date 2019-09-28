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
cat << EOF | try 2
4 150
150 140 100 200
EOF

## test case 2
cat << EOF | try 0
1 500
499
EOF

## test case 2
cat << EOF | try 5
5 1
100 200 300 400 500
EOF
