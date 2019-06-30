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
cat << EOF | try 2
6
9 1 4 4 6 7
EOF

## test case 2
cat << EOF | try 0
8
9 1 14 5 5 4 4 14
EOF

## test case 3
cat << EOF | try 42685
14
99592 10342 29105 78532 83018 11639 92015 77204 30914 21912 34519 80835 100000 1
EOF
