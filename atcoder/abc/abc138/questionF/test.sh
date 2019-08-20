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
cat << EOF | try 3
2 3
EOF

## test case 2
cat << EOF | try 604
10 100
EOF

## test case 3
cat << EOF | try 68038601
1 1000000000000000000
EOF
