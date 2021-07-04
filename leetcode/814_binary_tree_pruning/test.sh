#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

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
cat << EOF | try "[1,null,0,null,1]"
5
1 null 0 0 1
EOF

## test case 2
cat << EOF | try "[1,null,1,null,1]"
7
1 0 1 0 0 0 1
EOF

cat << EOF | try "[0,null,0,1,1,null,1,null,1]"
13
0 null 0 1 1 null 1 null 1 null null null null
EOF
