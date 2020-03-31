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
cat << EOF | try 7 4 1 8 5 2 9 6 3
3
1 2 3
4 5 6
7 8 9
EOF

## test case 2
cat << EOF | try 13 9 5 1 14 10 6 2 15 11 7 3 16 12 8 4
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
EOF
