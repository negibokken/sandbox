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
cat << EOF | try 1 2 3 4
4 34
1 2 0 0
EOF

## test case 2
cat << EOF | try 4 5 5
3 181
2 7 4
EOF

## test case 2
cat << EOF | try 1 0 0 0 0 0 0 0 0 0 0
10 1
9 9 9 9 9 9 9 9 9 9
EOF
