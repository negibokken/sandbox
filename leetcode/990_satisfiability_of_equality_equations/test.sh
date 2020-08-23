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
cat << EOF | try false
2
a==b
b!=a
EOF

## test case 2
cat << EOF | try true
2
b==a
a==b
EOF

## test case 2
cat << EOF | try true
3
a==b
b==c
a==c
EOF

## test case 2
cat << EOF | try false
3
a==b
b!=c
c==a
EOF

## test case 2
cat << EOF | try true
3
c==c
b==d
x!=z
EOF

## test case 2
cat << EOF | try false
4
a==b
c==d
a==c
a!=d
EOF
