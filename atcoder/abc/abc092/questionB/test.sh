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
cat << EOF | try 8
3
7 1
2
5
10
EOF

## test case 2
cat << EOF | try 29
2
8 20
1
10
EOF

## test case 2
cat << EOF | try 56
5
30 44
26
18
81
18
6
EOF
