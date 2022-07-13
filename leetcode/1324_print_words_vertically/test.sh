#!/bin/bash

try() {
  file=$1
  expected="${@:2:($#-1)}"
  input=`cat -`

  actual=`echo "$input" | python3 ./$file`

  actual=`echo "$actual"`
  # actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try $file "['HAY', 'ORO', 'WEU']"
"HOW ARE YOU"
EOF

## test case 2
cat << EOF | try $file "['TBONTB', 'OEROOE', '   T']"
"TO BE OR NOT TO BE"
EOF

## test case 3
cat << EOF | try $file "['CIC', 'OSO', 'N M', 'T I', 'E N', 'S G', 'T']"
"CONTEST IS COMING"
EOF

done
