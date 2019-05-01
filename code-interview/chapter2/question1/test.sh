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
cat << EOF | try 1 2 3 4 5
8
1 2 2 3 3 3 4 5
EOF

## test case 1
cat << EOF | try 1 2 3 4 5 6
14
1 2 2 3 3 3 4 4 3 3 3 5 4 6
EOF
