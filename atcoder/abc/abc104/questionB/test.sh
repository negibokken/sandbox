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
cat << EOF | try AC
AtCoder
EOF

## test case 2
cat << EOF | try WA
ACoder
EOF

## test case 2
cat << EOF | try WA
AcycliC
EOF

## test case 2
cat << EOF | try WA
AtCoCo
EOF

## test case 2
cat << EOF | try WA
Atcoder
EOF
