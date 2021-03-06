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
2 11 4
EOF

## test case 2
cat << EOF | try 3
3 9 5
EOF

## test case 2
cat << EOF | try 0
100 1 10
EOF
