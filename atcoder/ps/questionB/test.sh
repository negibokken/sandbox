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
cat << EOF | try 10
4 5
EOF

## test case 1
cat << EOF | try 10
5 4
EOF

## test case 2
cat << EOF | try 11
7 3
EOF

## test case 2
cat << EOF | try 1
1 3
EOF

## test case 2
cat << EOF | try 1
3 1
EOF

## test case 2
cat << EOF | try 500000000000000000
1000000000 1000000000
EOF
