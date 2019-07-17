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
cat << EOF | try 12
2 5
4 9
2 4
EOF

## test case 2
cat << EOF | try 130
4 30
6 18
2 5
3 10
7 9
EOF

## test case 2
cat << EOF | try 100000000000000
1 100000
1000000000 100000
EOF
