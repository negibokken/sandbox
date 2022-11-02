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
cat << EOF | try $file 15
[1,2,3,4,5,null,6,7,null,null,null,null,8]
EOF

## test case 2
cat << EOF | try $file 19
[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
EOF

done
