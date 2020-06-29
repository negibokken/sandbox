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
7
3 9 20 -1 -1 15 7
EOF

## test case 1
cat << EOF | try false
9
1 2 2 3 3 -1 -1 4 4
EOF

## test case 1
cat << EOF | try false
15
1 2 2 3 -1 -1 3 4 -1 -1 -1 -1 -1 -1 4
EOF
