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
cat << EOF | try 8
5 10 7
8 10 3 6
EOF

## test case 2
cat << EOF | try 0
4 100 60
100 100 100
EOF

## test case 2
cat << EOF | try -1
4 100 60
0 0 0
EOF
