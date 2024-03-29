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
cat<<EOF|try $file "['null','null','true','false','true','null','true']"
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
EOF

done
