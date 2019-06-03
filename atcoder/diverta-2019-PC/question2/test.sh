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
cat << EOF | try 4
1 2 3 4
EOF

## test case 2
cat << EOF | try 87058
13 1 4 3000
EOF

## test case 2
cat << EOF | try 3
1 1 1 3000
EOF
