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
cat << EOF | try 2
["leetcode","is","amazing","as","is"]
["amazing","leetcode","is"]
EOF

## test case 2
cat << EOF | try 0
["b","bb","bbb"]
["a","aa","aaa"]
EOF

## test case 2
cat << EOF | try 1
["a","ab"]
["a","a","a","ab"]
EOF
