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
cat << EOF | try 1
3 2 6
EOF

## test case 2
cat << EOF | try 0
3 1 3
EOF

## test case 2
cat << EOF | try 4
5 10 1
EOF
