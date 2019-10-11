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
6
aabbca
EOF

## test case 2
cat << EOF | try 1
10
aaaaaaaaaa
EOF

## test case 2
cat << EOF | try 9
45
tgxgdqkyjzhyputjjtllptdfxocrylqfqjynmfbfucbir
EOF
