#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  #actual=`echo $actual`
  #expected=`echo $expected`

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
cat << EOF | try 40
4
100 150 130 120
EOF

## test case 2
cat << EOF | try 40
4
100 125 80 110
EOF

## test case 3
cat << EOF | try 310
9
314 159 265 358 979 323 846 264 338
EOF
