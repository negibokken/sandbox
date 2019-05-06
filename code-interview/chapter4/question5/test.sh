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
cat << EOF | try false
7
6 5 3 1 3 4 3
EOF

## test case 2
cat << EOF | try false
4
3 4 3 2
EOF

## test case 1
cat << EOF | try true
7
1 2 3 4 5 6 7
EOF
