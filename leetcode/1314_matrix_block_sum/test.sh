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
cat << EOF | try 12 21 16 27 45 33 24 39 28
3 3 1
1 2 3
4 5 6
7 8 9
EOF

## test case 2
cat << EOF | try 45 45 45 45 45 45 45 45 45
3 3 2
1 2 3
4 5 6
7 8 9
EOF


cat << EOF | try 45 45 45 45 45 45 45 45 45
3 4 3
67 64 78
99 98 38
82 46 46
6 52 55
55 99 45
EOF
