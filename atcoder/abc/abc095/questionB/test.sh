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
cat << EOF | try 9
3 1000
120
100
140
EOF

## test case 2
cat << EOF | try 4
4 360
90
90
90
90
EOF

## test case 2
cat << EOF | try 26
5 3000
150
130
150
130
110
EOF
