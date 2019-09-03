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
cat << EOF | try Yes
4 7 9 3
EOF

## test case 2
cat << EOF | try No
100 10 1 2
EOF

## test case 2
cat << EOF | try Yes
10 10 10 1
EOF

## test case 2
cat << EOF | try Yes
1 100 2 10
EOF
