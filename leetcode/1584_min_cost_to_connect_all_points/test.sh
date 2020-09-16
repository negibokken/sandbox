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
cat << EOF | try 20
5
0 0
2 2
3 10
5 2
7 0
EOF

## test case 2
cat << EOF | try 18
3
3 12
-2 5
-4 1
EOF

## test case 2
cat << EOF | try 4
4
0 0
1 1
1 0
-1 1
EOF

## test case 2
cat << EOF | try 4000000
2
-1000000 -1000000
1000000 1000000
EOF

## test case 2
cat << EOF | try 0
1
0 0
EOF

## test case 2
cat << EOF | try 53
4
2 -3
-17 -8
13 8
-17 -15
EOF
