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
cat << EOF | try "4 3 3 4"
4
2 4 4 3
EOF

## test case 2
cat << EOF | try "2 1"
2
1 2
EOF

## test case 2
cat << EOF | try "4 4 4 4 4 4"
6
5 5 4 4 3 3
EOF
