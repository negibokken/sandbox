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
1214
4
EOF

## test case 2
cat << EOF | try 3
3
157
EOF

## test case 2
cat << EOF | try 2
299792458
9460730472580800
EOF
