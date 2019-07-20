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
cat << EOF | try 48000.000000
2
10000 JPY
0.10000000 BTC
EOF

## test case 2
cat << EOF | try 138000000.003800
3
100000000 JPY
100.00000000 BTC
0.00000001 BTC
EOF
