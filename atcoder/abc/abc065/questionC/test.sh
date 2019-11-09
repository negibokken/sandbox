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
cat << EOF | try 8
2 2
EOF

## test case 2
cat << EOF | try 12
3 2
EOF

## test case 2
cat << EOF | try 0
1 8
EOF

## test case 2
cat << EOF | try 530123477
100000 100000
EOF
