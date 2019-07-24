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
cat << EOF | try 2.6666666667
8 3
EOF

## test case 2
cat << EOF | try 99.0000000000
99 1
EOF

## test case 2
cat << EOF | try 0.0100000000
1 100
EOF
