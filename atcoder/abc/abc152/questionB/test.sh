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
cat << EOF | try 3333
4 3
EOF

## test case 2
cat << EOF | try 7777777
7 7
EOF

## test case 2
cat << EOF | try 3333
3 4
EOF
