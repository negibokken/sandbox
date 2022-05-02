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
cat << EOF | try $file "[[1,2],[2,3],[3,4]]"
[4,2,1,3]
EOF

## test case 2
cat << EOF | try $file "[[1,3]]"
[1,3,6,10,15]
EOF

## test case 3
cat << EOF | try $file "[[-14,-10],[19,23],[23,27]]"
[3,8,-10,23,19,-4,-14,27]
EOF

done
