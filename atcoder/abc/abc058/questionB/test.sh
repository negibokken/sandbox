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
cat << EOF | try xaybzc
xyz
abc
EOF

## test case 2
cat << EOF | try aattccooddeerrbreeggiunlnaerrccoonntteesstt
atcoderbeginnercontest
atcoderregularcontest
EOF

## a = b
cat << EOF | try acbd
ab
cd
EOF

## a > b
cat << EOF | try acbde
abe
cd
EOF

## a = b
cat << EOF | try ab
a
b
EOF

## a > b
cat << EOF | try abb
ab
b
EOF

## a > b
cat << EOF | try abb
a
bb
EOF
