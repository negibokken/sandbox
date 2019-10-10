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
cat << EOF | try 3
3 20
EOF

## test case 2
cat << EOF | try 3
25 100
EOF

## test case 2
cat << EOF | try 31
314159265 358979323846264338
EOF
