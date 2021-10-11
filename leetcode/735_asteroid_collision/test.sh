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
cat << EOF | try "[5, 10]"
[5,10,-5]
EOF

## test case 2
cat << EOF | try "[]"
[8,-8]
EOF

## test case 3
cat << EOF | try "[10]"
[10,2,-5]
EOF

## test case 4
cat << EOF | try "[-2, -1, 1, 2]"
[-2,-1,1,2]
EOF
