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
4
2 10 8 40
EOF

## test case 2
cat << EOF | try 1
4
5 13 8 1000000000
EOF

## test case 3
cat << EOF | try 1000000000
3
1000000000 1000000000 1000000000
EOF
