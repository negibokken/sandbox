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
cat << EOF | try 5
4
1 4 6 3
EOF

## test case 2
cat << EOF | try 999999999
2
1000000000 1
EOF

## test case 2
cat << EOF | try 0
5
1 1 1 1 1
EOF
