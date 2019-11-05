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
cat << EOF | try 50
0 75 25 100
EOF

## test case 2
cat << EOF | try 0
0 33 66 99
EOF

## test case 2
cat << EOF | try 60
10 90 20 80
EOF
