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
4 2 9
EOF

## test case 2
cat << EOF | try 7
4 2 7
EOF

## test case 2
cat << EOF | try 8
4 2 8
EOF
