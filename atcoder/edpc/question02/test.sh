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
cat << EOF | try 30
5 3
10 30 40 50 20
EOF

## test case 2
cat << EOF | try 20
3 1
10 20 10
EOF

## test case 3
cat << EOF | try 40
10 4
40 10 20 70 80 10 20 70 80 60
EOF
