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
cat << EOF | try 4
7
3 1 4 1 5 9 2
EOF

## test case 2
cat << EOF | try 3
10
0 1 2 3 4 5 6 7 8 9
EOF

## test case 2
cat << EOF | try 1
1
99999
EOF
