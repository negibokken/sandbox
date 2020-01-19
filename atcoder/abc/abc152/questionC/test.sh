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
5
4 2 5 1 3
EOF

## test case 2
cat << EOF | try 4
4
4 3 2 1
EOF

## test case 2
cat << EOF | try 1
6
1 2 3 4 5 6
EOF

## test case 2
cat << EOF | try 4
8
5 7 4 2 6 8 1 3
EOF
