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
cat << EOF | try 2
5
10 4 8 7 3
EOF

## test case 2
cat << EOF | try 3
7
4 4 5 6 6 5 5
EOF

## test case 2
cat << EOF | try 0
4
1 2 3 4
EOF
