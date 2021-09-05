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
cat << EOF | try "[1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6]"
[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
EOF

## test case 2
cat << EOF | try "[1, 3, 2]"
[1,2,null,3]
EOF

## test case 3
cat << EOF | try "[]"
[]
EOF
