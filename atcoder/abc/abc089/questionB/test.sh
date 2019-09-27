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
cat << EOF | try Four
6
G W Y P Y W
EOF

## test case 2
cat << EOF | try Three
9
G W W G P W P G G
EOF

## test case 2
cat << EOF | try Four
8
P Y W G Y W Y Y
EOF
