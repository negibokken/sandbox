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
13
5 4 8 11 -1 13 4 7 2 -1 -1 -1 1
22
EOF

## test case 2
cat << EOF | try false
3
1 2 3
5
EOF

## test case 2
cat << EOF | try false
2
1 2
0
EOF

## test case 2
cat << EOF | try false
2
1 2
1
EOF
