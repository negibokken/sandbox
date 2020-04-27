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
cat << EOF | try 45
5 3 100 60
86
23
49
39
EOF

## test case 2
cat << EOF | try 0
5 3 100 60
92
100
95
99
EOF

## test case 2
cat << EOF | try -1
5 3 100 60
18
42
29
31
EOF

## test case 2
cat << EOF | try 986132796
13 10 1000000000 645245296
492014535
611893452
729291030
392019922
293849201
474839528
702912832
341845861
102495671
908590572
812912432
129855439
EOF
