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
cat << EOF | try 9
3 3
2 13 8
EOF

## test case 2
cat << EOF | try 6
4 4
1 9 3 5
EOF

## test case 2
cat << EOF | try 0
1 100000
1000000000
EOF

## test case 2
cat << EOF | try 9500000000
10 1
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
EOF
