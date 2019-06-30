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
cat << EOF | try 2
5
1 3 5 4 2
EOF

## test case 2
cat << EOF | try 5
9
9 6 3 2 5 8 7 4 1
EOF
