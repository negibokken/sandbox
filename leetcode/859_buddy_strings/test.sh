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
cat << EOF | try true
ab
ba
EOF

## test case 2
cat << EOF | try false
ab
ab
EOF

## test case 2
cat << EOF | try true
aa
aa
EOF

## test case 2
cat << EOF | try true
aaaaaaabc
aaaaaaacb
EOF

## test case 2
cat << EOF | try false
null
aa
EOF

## test case 2
cat << EOF | try false
abcd
badc
EOF
