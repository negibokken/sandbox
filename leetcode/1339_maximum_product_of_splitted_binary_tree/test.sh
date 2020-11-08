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
cat << EOF | try 110
6
1 2 3 4 5 6
EOF

## test case 2
cat << EOF | try 90
9
1 -1 2 3 4 -1 -1 5 6
EOF
exit
## test case 2
cat << EOF | try 1025
11
2 3 9 10 7 8 6 5 4 11 1
EOF

## test case 2
cat << EOF | try 1
2
1 1
EOF
