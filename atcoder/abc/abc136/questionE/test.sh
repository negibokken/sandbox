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
cat << EOF | try 7
2 3
8 20
EOF

## test case 2
cat << EOF | try 8
2 10
3 5
EOF

## test case 1
cat << EOF | try 7
4 5
10 1 2 22
EOF

## test case 2
cat << EOF | try 5
8 7
1 7 5 6 8 2 6 5
EOF
