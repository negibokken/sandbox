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
5 2
1 1 2 2 5
EOF

## test case 2
cat << EOF | try 0
4 4
1 1 2 2
EOF

## test case 2
cat << EOF | try 3
10 3
5 1 3 2 4 1 1 2 3 4
EOF
