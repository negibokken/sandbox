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
cat << EOF | try 9
10
EOF

## test case 2
cat << EOF | try 1
1
EOF

## test case 2
cat << EOF | try 1
2
EOF

## test case 2
cat << EOF | try 1
3
EOF

## test case 2
cat << EOF | try 4
4
EOF

## test case 2
cat << EOF | try 961
999
EOF

## test case 2
cat << EOF | try 1000
1000
EOF
