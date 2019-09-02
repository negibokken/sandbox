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
cat << EOF | try 3
4 10
EOF

## test case 2
cat << EOF | try 2
8 9
EOF

## test case 2
cat << EOF | try 1
8 8
EOF

## test case 2
cat << EOF | try 1
20 8
EOF

## test case 2
cat << EOF | try 7
2 8
EOF

## test case 2
cat << EOF | try 3
5 10
EOF

## test case 2
cat << EOF | try 0
5 1
EOF

## test case 2
cat << EOF | try 10
3 20
EOF

## test case 2
cat << EOF | try 0
3 1
EOF
