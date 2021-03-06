#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

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
cat << EOF | try 9
10 7 100
EOF

## test case 2
cat << EOF | try 1000000000
2 1 100000000000
EOF

## test case 2
cat << EOF | try 0
1000000000 1000000000 100
EOF

## test case 2
cat << EOF | try 254309
1234 56789 314159265
EOF
