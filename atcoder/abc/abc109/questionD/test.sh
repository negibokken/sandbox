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
cat << EOF | try
2 3
1 2 3
0 1 1
EOF

## test case 2
cat << EOF | try
3 2
1 0
2 1
1 0
EOF

## test case 2
cat << EOF | try
1 5
9 9 9 9 9
EOF
