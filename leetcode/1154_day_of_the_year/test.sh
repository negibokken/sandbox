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
cat << EOF | try 9
2019-01-09
EOF

## test case 2
cat << EOF | try 41
2019-02-10
EOF

## test case 2
cat << EOF | try 60
2003-03-01
EOF

## test case 2
cat << EOF | try 61
2004-03-01
EOF
