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
cat << EOF | try 5
3 1
4 2 3
EOF

## test case 2
cat << EOF | try 6
4 3
3 -1 0 2
EOF

## test case 2
cat << EOF | try 13
5 2
2 -3 -1 5 -4
EOF
