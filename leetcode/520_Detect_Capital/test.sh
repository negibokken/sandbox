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
cat << EOF | try True
USA
EOF

## test case 2
cat << EOF | try False
FlaG
EOF

## test case 2
cat << EOF | try True
flag
EOF

## test case 2
cat << EOF | try False
FFFFFFFFFFFFFFFFFFFFf
EOF

## test case 2
cat << EOF | try True
Google
EOF

## test case 2
cat << EOF | try False
ffffffffffffffffffffF
EOF
