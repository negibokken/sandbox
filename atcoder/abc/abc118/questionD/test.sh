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
cat << EOF | try 777773
20 4
3 7 8 4
EOF

## test case 2
cat << EOF | try 71111111111111111111111111111111111111111111111111
101 9
9 8 7 6 5 4 3 2 1
EOF

## test case 2
cat << EOF | try 654
15 3
5 4 6
EOF
