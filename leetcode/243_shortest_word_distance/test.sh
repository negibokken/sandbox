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
cat << EOF | try $file 3
["practice", "makes", "perfect", "coding", "makes"]
"coding"
"practice"
EOF

## test case 2
cat << EOF | try $file 1
["practice", "makes", "perfect", "coding", "makes"]
"makes"
"coding"
EOF

cat << EOF | try $file 1
["a","a","b","b"]
"a"
"b"
EOF

done
