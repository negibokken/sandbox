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
cat << EOF | try 7
11
-40 -20 -1 1 2 3 5 7 9 12 13
EOF

## test case 2
cat << EOF | try 7
11
-10 -5 2 2 2 3 4 7 9 12 13
EOF
