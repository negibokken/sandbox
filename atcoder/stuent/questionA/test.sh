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
cat << EOF | try 10
15 40
EOF

## test case 2
cat << EOF | try 5
12 31
EOF

## test case 2
cat << EOF | try 0
1 1
EOF
