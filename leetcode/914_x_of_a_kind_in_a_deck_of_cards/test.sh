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
8
1 2 3 4 4 3 2 1
EOF

## test case 2
cat << EOF | try false
8
1 1 1 2 2 2 3 3
EOF

## test case 2
cat << EOF | try false
1
1
EOF

## test case 2
cat << EOF | try true
2
1 1
EOF

## test case 2
cat << EOF | try true
6
1 1 2 2 2 2
EOF
