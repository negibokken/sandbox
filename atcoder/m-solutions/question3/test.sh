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
cat << EOF | try 2
1 25 25 50
EOF

## test case 2
cat << EOF | try 312500008
4 50 50 0
EOF

## test case 2
cat << EOF | try 104136146
100000 31 41 28
EOF
