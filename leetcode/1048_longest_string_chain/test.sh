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
cat << EOF | try 4
["a","b","ba","bca","bda","bdca"]
EOF

## test case 2
cat << EOF | try 5
["xbc","pcxbcf","xb","cxbc","pcxbc"]
EOF

## test case 3
cat << EOF | try 1
["abcd","dbqca"]
EOF
