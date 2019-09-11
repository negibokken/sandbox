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
cat << EOF | try 3 4 7 8
3 8 2
EOF

## test case 2
cat << EOF | try 4 5 6 7 8
4 8 3
EOF

## test case 2
cat << EOF | try 2 3 4 5 6 7 8 9
2 9 100
EOF
