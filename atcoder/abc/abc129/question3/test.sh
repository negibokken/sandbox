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
cat << EOF | try 4
6 1
3
EOF

## test case 2
cat << EOF | try 0
10 2
4
5
EOF

## test case 2
cat << EOF | try 608200469
100 5
1
23
45
67
89
EOF
