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
cat << EOF | try 1
0 1
EOF

## test case 1
cat << EOF | try 5
0 5
EOF

## test case 1
cat << EOF | try 10
0 10
EOF

## test case 1
cat << EOF | try 101
0 100
EOF

## test case 2
cat << EOF | try 1100
1 11
EOF

## test case 2
cat << EOF | try 100
1 1
EOF

## test case 2
cat << EOF | try 10100
1 100
EOF

## test case 2
cat << EOF | try 10000
2 1
EOF

## test case 2
cat << EOF | try 850000
2 85
EOF

## test case 2
cat << EOF | try 1010000
2 100
EOF
