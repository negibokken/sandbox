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
cat << EOF | try true
5 0 4
0 1 1 0 0
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
EOF

## test case 2
cat << EOF | try false
5 0 3
0 1 1 0 0
0 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
EOF

## test case 3
cat << EOF | try false
6 0 5
0 1 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 1 0 0
0 1 1 0 0 0
0 0 0 0 0 0
EOF

## test case 4
cat << EOF | try true
6 0 5
0 1 1 0 0 1
0 0 0 0 0 1
0 0 0 0 1 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0
EOF

## test case 4
cat << EOF | try true
6 0 5
0 1 0 0 0 0
0 0 0 0 1 0
0 0 0 0 0 1
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 0 0
EOF
