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
3 1
1 2 1
EOF

## test case 2
cat << EOF | try 2
6 5
1 2 1
2 3 2
1 3 3
4 5 4
5 6 5
EOF

## test case 2
cat << EOF | try 99999
100000 1
1 100000 100
EOF
