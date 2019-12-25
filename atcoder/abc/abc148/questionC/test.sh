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
cat << EOF | try 6
2 3
EOF

## test case 2
cat << EOF | try 18696
123 456
EOF

## test case 2
cat << EOF | try 9999900000
100000 99999
EOF
