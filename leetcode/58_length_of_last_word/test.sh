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
cat << EOF | try 5
"Hello World"
EOF

## test case 2
cat << EOF | try 4
"   fly me   to   the moon    "
EOF

## test case 3
cat << EOF | try 6
"luffy is still joyboy"
EOF

## test case 4
cat << EOF | try 1
"a"
EOF
