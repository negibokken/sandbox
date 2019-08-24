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
cat << EOF | try 3
2 2
2 1
EOF

## test case 2
cat << EOF | try 0
3 5
1 1 1
EOF

## test case 2
cat << EOF | try 185297239
10 998244353
10 9 8 7 5 6 3 4 2 1
EOF

## test case 2
cat << EOF | try 12
3 3
1 3 2
EOF
