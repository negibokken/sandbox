#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  expected=`echo "$expected"`

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
3
NYY
YNY
YYN
EOF

## test case 2
cat << EOF | try 4
5
NYNNN
YNYNN
NYNYN
NNYNY
NNNYN
EOF

## test case 2
cat << EOF | try 8
10
NNNNYNNNNN
NNNNYNYYNN
NNNYYYNNNN
NNYNNNNNNN
YYYNNNNNNY
NNYNNNNNYN
NNYNNNNYNN
NYNNNNYNNN
NNNNNYNNNN
NNNNYNNNNN
EOF