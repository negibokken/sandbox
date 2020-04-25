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
cat << EOF | try 8
5
1 2 3 2 1
EOF

## test case 2
cat << EOF | try 10
4
1 2 3 4
EOF

## test case 2
cat << EOF | try 8
6
3 3 4 1 2 2
EOF

## test case 2
cat << EOF | try 10
6
1 5 2 3 4 2
EOF

