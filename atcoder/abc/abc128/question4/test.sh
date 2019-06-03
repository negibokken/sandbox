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
cat << EOF | try 14
6 4
-10 8 2 1 2 6
EOF

## test case 2
cat << EOF | try 44
6 4
-6 -100 50 -2 -5 -3
EOF

## test case 2
cat << EOF | try 0
6 3
-6 -100 50 -2 -5 -3
EOF
