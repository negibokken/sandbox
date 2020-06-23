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
121
EOF

## test case 2
cat << EOF | try false
-121
EOF

## test case 2
cat << EOF | try true
0
EOF

## test case 2
cat << EOF | try true
9
EOF

## test case 2
cat << EOF | try false
1234
EOF
