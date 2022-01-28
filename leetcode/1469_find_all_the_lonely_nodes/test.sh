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
cat << EOF | try "[4]"
[1,2,3,null,4]
EOF

## test case 2
cat << EOF | try "[6,2]"
[7,1,4,6,null,5,3,null,null,null,null,null,2]
EOF

## test case 2
cat << EOF | try "[77,55,33,66,44,22]"
[11,99,88,77,null,null,66,55,null,null,44,33,null,null,22]
EOF
