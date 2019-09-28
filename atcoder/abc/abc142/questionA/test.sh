#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    # echo "$input => $actual"
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 0.500000000
4
EOF

## test case 2
cat << EOF | try 0.600000000
5
EOF

## test case 2
cat << EOF | try 1.000000000
1
EOF
