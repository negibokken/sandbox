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
4 burg
i love eating burger
EOF

## test case 2
cat << EOF | try 2
6 pro
this problem is an easy problem
EOF

## test case 2
cat << EOF | try -1
3 you
i am tired
EOF

## test case 2
cat << EOF | try 4
4 pill
i use triple pillow
EOF

## test case 2
cat << EOF | try -1
5 they
hello from the other side
EOF
