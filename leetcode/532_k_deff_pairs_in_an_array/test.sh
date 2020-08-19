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
5 2
3 1 4 1 5
EOF

## test case 2
cat << EOF | try 4
5 1
1 2 3 4 5
EOF

## test case 2
cat << EOF | try 1
5 0
1 3 1 5 4
EOF
