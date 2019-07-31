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
cat << EOF | try 34
1234567876
EOF

## test case 2
cat << EOF | try 0
35753
EOF

## test case 3
cat << EOF | try 642
1111111111
EOF
