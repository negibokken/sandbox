#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  # actual=`echo $actual`
  # expected=`echo $expected`

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
cat << EOF | try 4
4 5
0 0 1 0 0
1 0 0 0 0
0 0 0 1 0
0 0 0 1 0
EOF

## test case 1
cat << EOF | try 16
4 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
EOF

## test case 1
cat << EOF | try 0
4 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
EOF

