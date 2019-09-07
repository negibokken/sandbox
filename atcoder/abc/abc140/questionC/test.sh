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
cat << EOF | try 9
3
2 5
EOF

## test case 2
cat << EOF | try 6
2
3
EOF

## test case 2
cat << EOF | try 53
6
0 153 10 10 23
EOF
