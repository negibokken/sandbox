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
cat << EOF | try 3
7 3
6 5 3 1 3 4 3
EOF

## test case 2
cat << EOF | try  4
4 2
3 4 3 2
EOF

## test case 3
cat << EOF | try 6
7 1
6 5 3 1 3 4 3
EOF
