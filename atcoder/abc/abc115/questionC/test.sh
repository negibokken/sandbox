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
5 3
10
15
11
14
12
EOF

## test case 2
cat << EOF | try 0
5 3
5
7
5
7
7
EOF

## test case 1
cat << EOF | try 0
5 3
3
3
1
1
3
EOF
