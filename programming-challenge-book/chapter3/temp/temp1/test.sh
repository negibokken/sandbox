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
10 15
5 1 3 5 10 7 4 9 2 8
EOF

## test case 2
cat << EOF | try 3
5 11
1 2 3 4 5
EOF
