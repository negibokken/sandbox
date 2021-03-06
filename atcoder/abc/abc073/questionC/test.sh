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
cat << EOF | try 1
3
6
2
6
EOF

## test case 2
cat << EOF | try 0
4
2
5
5
2
EOF

## test case 2
cat << EOF | try 2
6
12
22
16
22
18
12
EOF
