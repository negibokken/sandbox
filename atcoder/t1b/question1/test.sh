#!/bin/bash

try() {
  expected="$1"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try Yes
3 8 5
EOF

## test case 2
cat << EOF | try No
7 3 1
EOF

## test case 3
cat << EOF | try Yes
10 2 4
EOF

## test case 3
cat << EOF | try No
31 41 59
EOF
