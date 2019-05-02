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
cat << EOF | try 9 9 9
3
6 5 3
3 4 6
EOF

## test case 2
cat << EOF | try 2 4 3 2 1
4
3 4 3 2
9 9 9 9
EOF
