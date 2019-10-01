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
cat << EOF | try 2
2
2
2
100
EOF

## test case 2
cat << EOF | try 0
5
1
0
150
EOF

## test case 2
cat << EOF | try 213
30
40
50
6000
EOF
