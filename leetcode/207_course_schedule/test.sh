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
2 1
1 0
EOF

## test case 2
cat << EOF | try false
2 2
1 0
0 1
EOF

## test case 2
cat << EOF | try true
3 2
2 0
2 1
EOF

## test case 2
cat << EOF | try true
3 2
1 0
2 0
EOF
