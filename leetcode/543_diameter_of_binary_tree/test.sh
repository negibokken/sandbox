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
cat << EOF | try 3
5
1 2 3 4 5
EOF

## test case 2
cat << EOF | try 1
2
1 2
EOF


## test case 2
cat << EOF | try 8
4 -7 -3 null null -9 -3 9 -7 -4 null 6 null -6 -6 null null 0 6 5 null 9 null null -1 -4 null null null -2
EOF
