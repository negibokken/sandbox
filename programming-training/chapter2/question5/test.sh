#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo $actual`
  expected=`echo $expected`

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
cat << EOF | try 912
3 3
7 1 6
5 9 2
EOF

## test case 1
cat << EOF | try 1012
3 3
7 1 6
5 9 3
EOF

## test case 1
cat << EOF | try 712
3 2
7 1 6
5 9
EOF

