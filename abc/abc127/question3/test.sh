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
4 2
1 3
2 4
EOF

## test case 2
cat << EOF | try 1
10 3
3 6
5 7
6 9
EOF

## test case 3
cat << EOF | try 100000
100000 1
1 100000
EOF
