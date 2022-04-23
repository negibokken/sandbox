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
cat << EOF | try $file True
16
EOF

## test case 2
cat << EOF | try $file False
14
EOF

## test case 2
cat << EOF | try $file True
1
EOF

## test case 2
cat << EOF | try $file False
2000105819
EOF

## test case 2
cat << EOF | try $file True
4
EOF

done
