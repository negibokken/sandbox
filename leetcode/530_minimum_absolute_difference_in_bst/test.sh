#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

  actual=`echo "$actual"`
  actual=`echo $actual | sed 's/\n/ /g'`
  expected=`echo "$expected"`

  if [ "$actual" = "$expected" ]; then
    # echo "$input => $actual"
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 1
[4,2,6,1,3]
EOF

## test case 2
cat << EOF | try 1
[1,0,48,null,null,12,49]
EOF

cat << EOF | try 9
[236,104,701,null,227,null,911]
EOF

cat << EOF | try 1
[1,0,48,null,null,12,49]
EOF
