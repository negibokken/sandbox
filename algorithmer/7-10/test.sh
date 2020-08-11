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
cat << EOF | try 1
3
0 0
1 2
1
EOF

## test case 2
cat << EOF | try 0
3
0 0
2 2
1
EOF

## test case 2
cat << EOF | try 5
3
0 0
0 0
2
EOF

## test case 2
cat << EOF | try 243097320072600
100
0 0
0 99
50
EOF
