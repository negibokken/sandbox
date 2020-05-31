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
abba
dog cat cat dog
EOF

## test case 1
cat << EOF | try false
abba
dog cat cat fish
EOF

## test case 1
cat << EOF | try false
aaaa
dog cat cat dog
EOF

## test case 1
cat << EOF | try false
abba
dog dog dog dog
EOF
