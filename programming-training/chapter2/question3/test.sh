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
cat << EOF | try 6 5 3 3 4 3
7 3
6 5 3 1 3 4 3
EOF

## test case 1
cat << EOF | try 5 3 1 3 4 3
7 0
6 5 3 1 3 4 3
EOF

## test case 1
cat << EOF | try 6 5 3 1 3 4
7 6
6 5 3 1 3 4 3
EOF

