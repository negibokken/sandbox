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
cat << EOF | try 83
100 17
EOF

## test case 2
cat << EOF | try 0
48 58
EOF

## test case 2
cat << EOF | try 0
1000000000 1000000000
EOF
