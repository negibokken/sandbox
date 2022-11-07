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
cat << EOF | try $file "[0,1,2,1000000,1000001,1000002,5]"
[0,1,2,3,4,5]
3
4
[1000000,1000001,1000002]
EOF

## test case 2
cat << EOF | try $file "[0,1,1000000,1000001,1000002,1000003,1000004,6]"
[0,1,2,3,4,5,6]
2
5
[1000000,1000001,1000002,1000003,1000004]
EOF

done
