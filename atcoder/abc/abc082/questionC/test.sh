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
4
3 3 3 3
EOF

## test case 2
cat << EOF | try 2
5
2 4 1 4 2
EOF

## test case 2
cat << EOF | try 0
6
1 2 2 3 3 3
EOF

## test case 2
cat << EOF | try 1
1
1000000000
EOF

## test case 2
cat << EOF | try 5
8
2 7 1 8 2 8 1 8
EOF
