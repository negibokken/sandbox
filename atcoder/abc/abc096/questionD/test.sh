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
cat << EOF | try "3 5 7 11 31"
5
EOF

## test case 2
cat << EOF | try "2 3 5 7 11 13"
6
EOF

## test case 2
cat << EOF | try "2 5 7 13 19 37 67 79"
8
EOF
