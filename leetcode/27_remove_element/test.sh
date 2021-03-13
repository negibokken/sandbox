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
cat << EOF | try "2,2 2"
4 3
3 2 2 3
EOF

## test case 2
cat << EOF | try "5,0 1 4 0 3"
8 2
0 1 2 2 3 0 4 2
EOF
