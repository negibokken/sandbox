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
cat << EOF | try 11
4 2 5
1 2 5 7
EOF

## test case 2
cat << EOF | try 84
7 1 100
40 43 45 105 108 115 124
EOF

## test case 2
cat << EOF | try 12
7 1 2
24 35 40 68 72 99 103
EOF
