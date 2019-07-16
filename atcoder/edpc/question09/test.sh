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
cat << EOF | try 0.6120000000
3
0.30 0.60 0.80
EOF

## test case 2
cat << EOF | try 0.5000000000
1
0.5
EOF

## test case 2
cat << EOF | try 0.3821815872
5
0.42 0.01 0.42 0.99 0.42
EOF
