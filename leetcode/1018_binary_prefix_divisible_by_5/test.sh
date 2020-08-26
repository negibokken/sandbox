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
cat << EOF | try true false false
3
0 1 1
EOF

## test case 2
cat << EOF | try false false false
3
1 1 1
EOF

## test case 3
cat << EOF | try true false false false true false
6
0 1 1 1 1 1
EOF

## test case 3
cat << EOF | try false false false false false
5
1 1 1 0 1
EOF
