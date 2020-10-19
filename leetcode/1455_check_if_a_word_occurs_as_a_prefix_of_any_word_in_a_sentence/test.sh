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
cat << EOF | try 4
i love eating burger
burg
EOF

## test case 2
cat << EOF | try 2
this problem is an easy problem
pro
EOF

## test case 3
cat << EOF | try -1
i am tired
you
EOF

## test case 3
cat << EOF | try 4
i use triple pillow
pill
EOF

## test case 3
cat << EOF | try -1
hello from the other side
they
EOF
