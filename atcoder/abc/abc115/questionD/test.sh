#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 4
2 7
EOF

## test case 2
cat << EOF | try 0
1 1
EOF

## test case 3
cat << EOF | try 2160549382716056
50 4321098765432109
EOF
