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
cat << EOF | try true
11
0 2 1 -6 6 -7 9 1 2 0 1
EOF

## test case 2
cat << EOF | try false
11
0 2 1 -6 6 7 9 -1 2 0 1
EOF

## test case 2
cat << EOF | try true
10
3 3 6 5 -2 2 5 1 -9 4
EOF
