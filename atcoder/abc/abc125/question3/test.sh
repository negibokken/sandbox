#!/bin/bash

try() {
  expected="$1"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 2
3
7 6 8
EOF

## test case 1
cat << EOF | try 6
3
12 15 18
EOF


## test case 1
cat << EOF | try 1000000000
2
1000000000 1000000000
EOF


