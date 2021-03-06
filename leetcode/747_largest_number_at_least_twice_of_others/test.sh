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
cat << EOF | try 1
4
3 6 1 0
EOF

## test case 2
cat << EOF | try -1
4
1 2 3 4
EOF

## test case 2
cat << EOF | try -1
4
0 0 3 2
EOF
