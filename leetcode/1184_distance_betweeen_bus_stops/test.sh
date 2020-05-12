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
cat << EOF | try 1
4 0 1
1 2 3 4
EOF

## test case 1
cat << EOF | try 3
4 0 2
1 2 3 4
EOF

## test case 1
cat << EOF | try 4
4 0 3
1 2 3 4
EOF

cat << EOF | try 17
8 7 2
7 10 1 12 11 14 5 0
EOF
