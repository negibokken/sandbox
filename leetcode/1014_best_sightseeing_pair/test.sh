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
cat << EOF | try 11
5
8 1 5 2 6
EOF

## test case 1
cat << EOF | try 2
2
1 2
EOF

## test case 1
cat << EOF | try 7
3
1 3 5
EOF

## test case 1
cat << EOF | try 18
5
2 10 9 3 2
EOF

