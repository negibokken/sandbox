#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  # actual=`echo $actual`
  # expected=`echo $expected`

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
cat << EOF | try 2
3
3 1 4
EOF

## test case 2
cat << EOF | try 5
5
1 1 1 1 1
EOF

## test case 2
cat << EOF | try 4
6
40 1 30 2 7 20
EOF
