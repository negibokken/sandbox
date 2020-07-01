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
cat << EOF | try 15
3 3
3 7 8
9 11 13
15 16 17
EOF

## test case 2
cat << EOF | try 12
4 3
1 10 4 2
9 3 8 7
15 16 17 12
EOF
