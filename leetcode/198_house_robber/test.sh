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
cat << EOF | try 4
4
1 2 3 1
EOF

## test case 2
cat << EOF | try 12
5
2 7 9 3 1
EOF

## test case 2
cat << EOF | try 4
4
2 1 1 2
EOF
