#!/bin/bash

try() {
  file=$1
  expected="${@:2:($#-1)}"
  input=`cat -`

  actual=`echo "$input" | python3 ./$file`

  actual=`echo "$actual"`
  #actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try $file 1
["23:59","00:00"]
EOF

## test case 2
cat << EOF | try $file 0
["00:00","23:59","00:00"]
EOF

## test case 2
cat << EOF | try $file 60
["01:01","02:01"]
EOF

## test case 2
cat << EOF | try $file 59
["01:01","02:01", "03:00"]
EOF

done