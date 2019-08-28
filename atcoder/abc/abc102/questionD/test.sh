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
cat << EOF | try 2
5
3 2 4 1 2
EOF

## test case 2
cat << EOF | try 36
10
10 71 84 33 6 47 23 25 52 64
EOF

## test case 2
cat << EOF | try 999999994
7
1 2 3 1000000000 4 5 6
EOF
