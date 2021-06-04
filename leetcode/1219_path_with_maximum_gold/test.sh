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
cat << EOF | try 24
3 3
0 6 0
5 8 7
0 9 0
EOF

## test case 2
cat << EOF | try 2 3 3 4
3 5
1 0 7
2 0 6
3 4 5
0 3 0
9 0 20
EOF
