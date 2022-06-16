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
cat << EOF | try $file '["bread"]'
["bread"]
[["yeast","flour"]]
["yeast","flour","corn"]
EOF

## test case 2
cat << EOF | try $file '["bread","sandwitch"]'
["bread","sandwich"]
[["yeast","flour"],["bread","meat"]]
["yeast","flour","meat"]
EOF

cat << EOF | try $file '["bread","sandwich","burger"]'
["bread","sandwich","burger"]
[["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]]
["yeast","flour","meat"]
EOF

done
