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
cat << EOF | try 25
3
5
10
15
EOF

## test case 2
cat << EOF | try 35
3
10
10
15
EOF

## test case 2
cat << EOF | try 0
3
10
20
30
EOF
