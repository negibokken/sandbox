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
5
1 2 1 1 3
EOF

## test case 2
cat << EOF | try No
4
3 4 3 2
EOF

## test case 2
cat << EOF | try Yes
1
1000000
EOF
