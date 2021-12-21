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
cat << EOF | try True
1
EOF

## test case 2
cat << EOF | try True
16
EOF

## test case 3
cat << EOF | try False
3
EOF

## test case 4
cat << EOF | try False
10
EOF

## test case 5
cat << EOF | try False
6
EOF
