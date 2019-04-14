#!/bin/bash

try() {
  expected="$1"
  actual=`cat - | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$(cat -) => $actual"
  else
    echo "$expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 4
5 1
00010
EOF

## test case 2
cat << EOF | try 8
14 2
11101010110011
EOF

## test case 3
cat << EOF | try 1
1 1
1
EOF
