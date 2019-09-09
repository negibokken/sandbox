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
5 3 3
1 2 4
EOF

## test case 2
cat << EOF | try 0
7 3 2
4 5 6
EOF

## test case 2
cat << EOF | try 3
10 7 5
1 2 3 4 6 8 9
EOF
