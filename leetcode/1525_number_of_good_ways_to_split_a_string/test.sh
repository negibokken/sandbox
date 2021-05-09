#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  #actual=`echo $actual | sed 's/\n/ /g'`
  expected=`echo "$expected"`

  if [ "$actual" = "$expected" ]; then
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 2
aacaba
EOF

## test case 2
cat << EOF | try 1
abcd
EOF

## test case 3
cat << EOF | try 4
aaaaa
EOF

## test case 4
cat << EOF | try 2
acbadbaada
EOF
