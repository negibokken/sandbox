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
cat << EOF | try 2
7
EOF

## test case 2
cat << EOF | try 27217477801
149696127901
EOF

## test case 2
cat << EOF | try 2
11
EOF

## test case 2
cat << EOF | try 3
12
EOF

## test case 2
cat << EOF | try 3
17
EOF

## test case 2
cat << EOF | try 4
18
EOF
