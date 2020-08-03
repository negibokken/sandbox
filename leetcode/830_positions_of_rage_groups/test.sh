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
cat << EOF | try "[[3,6]]"
abbxxxxzzy
EOF

## test case 2
cat << EOF | try "[]"
abc
EOF

## test case 2
cat << EOF | try "[[3,5],[6,9],[12,14]]"
abcdddeeeeaabbbcd
EOF
