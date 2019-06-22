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
cat << EOF | try 3 3
7
BBFBFBB
EOF

cat << EOF | try 2 2
7
BBFFFBB
EOF

cat << EOF | try 2 3
7
BBFBBBB
EOF
