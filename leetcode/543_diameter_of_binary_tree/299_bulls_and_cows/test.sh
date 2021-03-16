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
cat << EOF | try 1A3B
1807 7810
EOF

## test case 2
cat << EOF | try 1A1B
1123 0111
EOF

## test case 2
cat << EOF | try 0A0B
1 0
EOF

## test case 2
cat << EOF | try 1A0B
1 1
EOF

## test case 2
cat << EOF | try 3A0B
1122 1222
EOF
