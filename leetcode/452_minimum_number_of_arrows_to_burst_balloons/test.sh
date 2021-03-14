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
cat << EOF | try 2
4
1 16
2 8
1 6
7 12
EOF

## test case 2
cat << EOF | try 4
4
1 2
3 4
5 6
7 8
EOF

## test case 2
cat << EOF | try 2
4
1 2
2 3
3 4
4 5
EOF

## test case 2
cat << EOF | try 1
1
1 2
EOF

## test case 2
cat << EOF | try 1
2
2 3
2 3
EOF
