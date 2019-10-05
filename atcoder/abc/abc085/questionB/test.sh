#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

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
cat << EOF | try 3
4
10
8
8
6
EOF

## test case 2
cat << EOF | try 1
3
15
15
15
EOF

## test case 2
cat << EOF | try 4
7
50
30
50
100
50
80
30
EOF
