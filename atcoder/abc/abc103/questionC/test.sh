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
cat << EOF | try 10
3
3 4 6
EOF

## test case 2
cat << EOF | try 90
5
7 46 11 20 11
EOF

## test case 2
cat << EOF | try 4527
7
994 518 941 851 647 2 581
EOF
