#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  expected=`echo "$expected"`

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
cat << EOF | try 321
123
EOF

## test case 2
cat << EOF | try -321
-123
EOF

## test case 2
cat << EOF | try 21
120
EOF

cat << EOF | try 0
1534236469
EOF

cat << EOF | try 0
-2147483648
EOF
