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
cat << EOF | try "[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]"
6
7 0
4 4
7 1
5 0
6 1
5 2
EOF

## test case 2
cat << EOF | try "[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]"
6
6 0
5 0
4 0
3 2
2 2
1 4
EOF
