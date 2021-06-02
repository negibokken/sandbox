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
cat << EOF | try 1 3 6 10
4
1 2 3 4
EOF

## test case 2
cat << EOF | try 1 2 3 4 5
5
1 1 1 1 1
EOF

## test case 2
cat << EOF | try 3 4 6 16 17
5
3 1 2 10 1
EOF
