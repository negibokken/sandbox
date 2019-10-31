#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    # echo "$input => $actual"
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 2
6
3 1 2 4 2 1
EOF

## test case 2
cat << EOF | try 0
4
1 2 3 4
EOF

## test case 2
cat << EOF | try 20
10
3 3 3 3 4 4 4 5 5 5
EOF

## test case 2
cat << EOF | try 20
20
1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4 5 5 5 5
EOF

## test case 2
cat << EOF | try 20
20
1 2 1 1 2 2 2 2 3 3 3 3 4 10 4 4 8 7 5 5
EOF
