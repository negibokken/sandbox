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
cat << EOF | try 14
3 7
1 6 3
EOF

## test case 2
cat << EOF | try 46
4 9
7 4 0 3
EOF

## test case 2
cat << EOF | try 1000000000000
1 0
1000000000000
EOF
