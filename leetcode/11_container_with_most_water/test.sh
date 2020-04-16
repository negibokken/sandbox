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
cat << EOF | try 49
9
1 8 6 2 5 4 8 3 7
EOF

## test case 1
cat << EOF | try 1
2
1 1
EOF

## test case 1
cat << EOF | try 36
7
2 3 10 5 7 8 9
EOF

## test case 1
cat << EOF | try 3
4
1 1 9 1
EOF

