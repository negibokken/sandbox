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
5
MASHIKE
RUMOI
OBIRA
HABORO
HOROKANAI
EOF

## test case 2
cat << EOF | try 0
4
ZZ
ZZZ
Z
ZZZZZZZZZZ
EOF

## test case 2
cat << EOF | try 7
5
CHOKUDAI
RNG
MAKOTO
AOKI
RINGO
EOF
