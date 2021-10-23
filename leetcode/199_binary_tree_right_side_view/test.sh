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
cat << EOF | try "[1, 3, 4]"
[1,2,3,null,5,null,4]
EOF

## test case 2
cat << EOF | try "[1, 3]"
[1,null,3]
EOF

## test case 2
cat << EOF | try "[]"
[]
EOF
