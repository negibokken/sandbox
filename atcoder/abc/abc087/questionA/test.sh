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
cat << EOF | try 84
1234
150
100
EOF

## test case 2
cat << EOF | try 28
1000
108
108
EOF

## test case 2
cat << EOF | try 0
579
123
456
EOF

## test case 2
cat << EOF | try 405
7477
549
593
EOF
