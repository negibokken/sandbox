#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

  actual=`echo "$actual"`
  #actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try 13
3 34
1
8 13 26
EOF

## test case 2
cat << EOF | try 12
7 45
2
7 11 16 20 28 34 38
EOF

## test case 2
cat << EOF | try 46
3 100
1
28 54 81
EOF

## test case 2
cat << EOF | try 26
3 100
2
28 54 81
EOF

## test case 2
cat << EOF | try 170
20 1000
4
51 69 102 127 233 295 350 388 417 466 469 523 553 587 720 739 801 855 926 954
EOF
