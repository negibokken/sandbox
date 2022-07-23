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
cat << EOF | try $file 0
[1,2,3,4,5]
1
3
3
EOF

## test case 2
cat << EOF | try $file 1
[3,2]
2
0
1
EOF

## test case 3
cat << EOF | try $file 0
[6,5,0,0]
2
1
5
EOF

done
