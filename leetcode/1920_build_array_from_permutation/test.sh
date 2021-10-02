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
cat << EOF | try "[0, 1, 2, 4, 5, 3]"
[0,2,1,5,3,4]
EOF

## test case 2
cat << EOF | try "[4, 5, 0, 1, 2, 3]"
[5,0,1,2,3,4]
EOF
