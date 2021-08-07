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
cat << EOF | try "[1, 4, 3, 2, 0]"
[12,28,46,32,50]
[50,12,32,46,28]
EOF

## test case 2
cat << EOF | try "[0, 1]"
[84,46]
[84,46]
EOF
