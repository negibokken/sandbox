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
cat << EOF | try ABC
1199
EOF

## test case 2
cat << EOF | try ARC
1200
EOF

## test case 2
cat << EOF | try ARC
2799
EOF

## test case 2
cat << EOF | try AGC
2800
EOF

## test case 2
cat << EOF | try AGC
4208
EOF
