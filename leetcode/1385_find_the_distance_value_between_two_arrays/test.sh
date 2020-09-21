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
3 4 2
4 5 8
10 9 1 8
6 5 3 1 3 4 3
EOF

## test case 2
cat << EOF | try 2
4 6 3
1 4 2 3
-4 -3 6 10 20 30
EOF

## test case 2
cat << EOF | try 1
4 5 6
2 1 100 3
-5 -2 -10 -3 7
EOF
