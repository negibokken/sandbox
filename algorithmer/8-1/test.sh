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
cat << EOF | try 1400
2 3
100 400 200
EOF

## test case 2
cat << EOF | try 1600
2 3
100 400 300
EOF

## test case 2
cat << EOF | try 4640
5 5
464 464 464
EOF

## test case 2
cat << EOF | try -100
1 4
20 -30 -10
EOF

## test case 2
cat << EOF | try 0
9 1
-1 -10 4
EOF
