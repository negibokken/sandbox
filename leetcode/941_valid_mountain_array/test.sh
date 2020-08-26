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
cat << EOF | try false
2
2 1
EOF

## test case 2
cat << EOF | try false
3
3 5 5
EOF

## test case 2
cat << EOF | try true
4
0 3 2 1
EOF

## test case 2
cat << EOF | try true
6
0 1 2 4 2 1
EOF

## test case 2
cat << EOF | try false
10
9 8 7 6 5 4 3 2 1 0
EOF

## test case 2
cat << EOF | try false
10
0 1 2 3 4 5 6 7 8 9
EOF
