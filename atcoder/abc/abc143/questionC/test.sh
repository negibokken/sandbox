#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    # echo "$input => $actual"
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 5
10
aabbbbaaca
EOF

## test case 2
cat << EOF | try 1
5
aaaaa
EOF

## test case 2
cat << EOF | try 10
20
xxzaffeeeeddfkkkkllq
EOF
