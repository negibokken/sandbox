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
cat << EOF | try 0
[5,3,2,4]
EOF

## test case 2
cat << EOF | try 1
[1,5,0,10,14]
EOF

## test case 3
cat << EOF | try 2
[6,6,0,1,1,4,6]
EOF

## test case 4
cat << EOF | try 1
[1,5,6,14,15]
EOF

## test case 5
cat << EOF | try 0
[1]
EOF

## test case 5
cat << EOF | try 1
[82,81,95,75,20]
EOF
