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
cat << EOF | try "[4, 5, 2, 7]"
[4,2,5,7]
EOF

## test case 2
cat << EOF | try "[2, 3]"
[2,3]
EOF

## test case 2
cat << EOF | try "[4, 3]"
[3,4]
EOF
