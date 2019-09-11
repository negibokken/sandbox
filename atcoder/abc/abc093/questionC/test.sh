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
2 5 4
EOF

## test case 2
cat << EOF | try 5
2 6 3
EOF

## test case 2
cat << EOF | try 23
31 41 5
EOF
