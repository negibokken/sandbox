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
cat << EOF | try 90
3 8
3 30
4 50
5 60
EOF

## test case 2
cat << EOF | try 5000000000
5 5
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
EOF

## test case 3
cat << EOF | try 17
6 15
6 5
5 6
6 4
6 6
3 5
7 2
EOF
