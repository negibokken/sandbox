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
cat << EOF | try 24
7
3 9 20 -1 -1 15 7
EOF

## test case 1
cat << EOF | try 4
5
1 2 3 4 5
EOF

cat << EOF | try -11
10
-9 -3 2 -1 4 4 0 -6 -1 -5
EOF
