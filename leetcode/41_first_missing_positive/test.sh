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
cat << EOF | try 3
1 2 0
EOF

## test case 2
cat << EOF | try 2
3 4 -1 1
EOF

## test case 2
cat << EOF | try 1
7 8 9 10 11 12
EOF

## test case 2
cat << EOF | try 1
2 2
EOF
