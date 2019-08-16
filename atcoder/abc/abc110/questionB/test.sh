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
cat << EOF | try "No War"
3 2 10 20
8 15 13
16 22
EOF

## test case 2
cat << EOF | try War
4 2 -48 -1
-20 -35 -91 -23
-22 66
EOF

## test case 3
cat << EOF | try War
5 3 6 8
-10 3 1 5 -100
100 6 14
EOF
