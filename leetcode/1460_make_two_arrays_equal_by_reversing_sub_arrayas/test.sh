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
4 4
1 2 3 4
2 4 1 3
EOF

## test case 2
cat << EOF | try true
1 1
7
7
EOF

## test case 2
cat << EOF | try true
2 2
1 12
12 1
EOF

## test case 2
cat << EOF | try false
3 3
3 7 9
3 7 11
EOF

## test case 2
cat << EOF | try true
5 5
1 1 1 1 1
1 1 1 1 1
EOF
