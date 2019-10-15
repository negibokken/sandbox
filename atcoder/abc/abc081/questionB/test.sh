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
3
8 12 40
EOF

## test case 2
cat << EOF | try 0
4
5 6 8 10
EOF

## test case 2
cat << EOF | try 8
6
382253568 723152896 37802240 379425024 404894720 471526144
EOF
