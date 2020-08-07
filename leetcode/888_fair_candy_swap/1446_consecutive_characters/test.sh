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
leetcode
EOF

## test case 2
cat << EOF | try 5
abbcccddddeeeeedcba
EOF

## test case 2
cat << EOF | try 5
triplepillooooow
EOF

## test case 2
cat << EOF | try 11
hooraaaaaaaaaaay
EOF

## test case 2
cat << EOF | try 1
tourist
EOF

## test case 2
cat << EOF | try 1
j
EOF
