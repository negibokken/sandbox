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
cat << EOF | try 6
3 4 5
EOF

## test case 1
cat << EOF | try 30
5 12 13
EOF

## test case 1
cat << EOF | try 630
45 28 53
EOF

