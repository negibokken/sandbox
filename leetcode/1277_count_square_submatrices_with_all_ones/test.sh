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
3 4
0 1 1 1
1 1 1 1
0 1 1 1
EOF

## test case 2
cat << EOF | try 7
3 3
1 0 1
1 1 0
1 1 0
EOF
