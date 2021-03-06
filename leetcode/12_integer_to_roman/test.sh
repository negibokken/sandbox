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
cat << EOF | try III
3
EOF

## test case 2
cat << EOF | try IV
4
EOF

## test case 2
cat << EOF | try IX
9
EOF

## test case 2
cat << EOF | try LVIII
58
EOF

## test case 2
cat << EOF | try MCMXCIV
1994
EOF
