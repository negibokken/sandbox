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
cat << EOF | try "5 6 7 8 9"
3 7
EOF

## test case 2
cat << EOF | try "-3 -2 -1 0 1 2 3"
4 0
EOF

## test case 2
cat << EOF | try 100
1 100
EOF
