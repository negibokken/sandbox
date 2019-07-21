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
cat << EOF | try 1 0 0 1
3
1 0 1
EOF

## test case 2
cat << EOF | try 0
5
0 0 0 0 0
EOF

## test case 2
cat << EOF | try 1 0 1 0 1
5
1 0 1 0 1
EOF

## test case 2
cat << EOF | try 3 1 0 1
5
1 0 1 0 0
EOF

## test case 2
cat << EOF | try 3 0 1 0 0 1 1 1 1
8
1 1 1 1 1 1 1 1
EOF

## test case 2
cat << EOF | try 3 1 1 0 1 1 1 1
8
1 1 1 1 1 1 1 0
EOF
