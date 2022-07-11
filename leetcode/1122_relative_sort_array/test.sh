#!/bin/bash

try() {
  file=$1
  expected="${@:2:($#-1)}"
  input=`cat -`

  actual=`echo "$input" | python3 ./$file`

  actual=`echo "$actual"`
  actual=`echo $actual | sed 's/\n/ /g'`
  expected=`echo "$expected"`

  if [ "$actual" = "$expected" ]; then
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

for file in `ls *.py`; do
echo $file "==="

## test case 1
cat << EOF | try $file "[2,2,2,1,4,3,3,9,6,7,19]"
[2,3,1,3,2,4,6,7,9,2,19]
[2,1,4,3,9,6]
EOF

## test case 2
cat << EOF | try $file "[22,28,8,6,17,44]"
[28,6,22,8,44,17]
[22,28,8,6]
EOF

done
