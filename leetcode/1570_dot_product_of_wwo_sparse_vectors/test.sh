#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

  actual=`echo "$actual"`
  # actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try 8
[1,0,0,2,3]
[0,3,0,4,0]
EOF

## test case 2
cat << EOF | try 0
[0,1,0,0,0]
[0,0,0,0,2]
EOF

## test case 2
cat << EOF | try 6
[0,1,0,0,2,0,0]
[1,0,0,0,3,0,4]
EOF
