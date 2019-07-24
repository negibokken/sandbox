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
cat << EOF | try 5
2 5
10 12 1 2 14
EOF

## test case 2
cat << EOF | try 19
3 7
-10 -3 0 9 -100 2 17
EOF

## test case 2
cat << EOF | try 0
100 1
-100000
EOF

