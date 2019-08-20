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
3 3
1 7 11
EOF

## test case 2
cat << EOF | try 24
3 81
33 105 57
EOF

## test case 3
cat << EOF | try 999999999
1 1
1000000000
EOF
