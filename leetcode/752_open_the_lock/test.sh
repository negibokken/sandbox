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
cat << EOF | try $file 6
["0201","0101","0102","1212","2002"]
"0202"
EOF

# ## test case 2
# cat << EOF | try $file 1
# ["8888"]
# "0009"
# EOF
# 
# ## test case 3
# cat << EOF | try $file -1
# ["8887","8889","8878","8898","8788","8988","7888","9888"]
# "8888"
# EOF

done
