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
cat << EOF | try 350 1400 301 399
2 3 4
100
600
400
900
1000
150
2000
899
799
EOF

## test case 2
cat << EOF | try 10000000000 10000000000 14999999998
1 1 3
1
10000000000
2
9999999999
5000000000
EOF
