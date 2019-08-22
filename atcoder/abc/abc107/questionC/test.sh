#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 40
5 3
-30 -10 10 20 50
EOF

## test case 2
cat << EOF | try 20
3 2
10 20 30
EOF

## test case 3
cat << EOF | try 0
1 1
0
EOF

## test case 3
cat << EOF | try 10
8 5
-9 -7 -4 -3 1 2 3 4
EOF
