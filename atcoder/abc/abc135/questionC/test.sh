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
2
3 5 2
4 5
EOF

## test case 2
cat << EOF | try 22
3
5 6 3 8
5 100 8
EOF

## test case 2
cat << EOF | try 3
2
100 1 1
1 100
EOF
