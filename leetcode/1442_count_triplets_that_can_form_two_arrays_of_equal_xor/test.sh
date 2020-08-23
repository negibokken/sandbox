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
cat << EOF | try 4
5
2 3 1 6 7
EOF

## test case 2
cat << EOF | try 10
5
1 1 1 1 1
EOF

## test case 2
cat << EOF | try 0
2
2 3
EOF

## test case 2
cat << EOF | try 3
5
1 3 5 7 9
EOF

## test case 2
cat << EOF | try 8
9
7 11 12 9 5 2 7 17 22
EOF
