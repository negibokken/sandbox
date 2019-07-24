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
4
3 8 5 1
EOF

## test case 2
cat << EOF | try No
4
3 8 4 1
EOF

## test case 2
cat << EOF | try No
10
1 8 10 5 8 12 34 100 11 3
EOF

