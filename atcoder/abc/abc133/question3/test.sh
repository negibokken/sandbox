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
2020 2040
EOF

## test case 2
cat << EOF | try 20
4 5
EOF

## test case 2
cat << EOF | try 0
2017 4034
EOF

## test case 2
cat << EOF | try 0
2017 4036
EOF

## test case 2
cat << EOF | try 0
1 123435809
EOF
