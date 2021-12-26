#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

  actual=`echo "$actual"`
  actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try 4
00100000000000000000000000000000
EOF

## test case 2
cat << EOF | try 3221225471
11111111111111111111111111111101
EOF

## test case 1
cat << EOF | try 964176192
00000010100101000001111010011100
EOF

## test case 2
cat << EOF | try 3221225471
11111111111111111111111111111101
EOF
