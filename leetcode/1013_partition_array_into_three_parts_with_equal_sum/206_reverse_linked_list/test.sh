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
cat << EOF | try 5 4 3 2 1
5
1 2 3 4 5
EOF

## test case 1
cat << EOF | try 1
1
1
EOF

## test case 1
cat << EOF | try 2 1
2
1 2
EOF

