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
cat << EOF | try 14
5
3 2 2 4 1
1 2 2 2 1
EOF

## test case 2
cat << EOF | try 5
4
1 1 1 1
1 1 1 1
EOF

## test case 3
cat << EOF | try 29
7
3 3 4 5 4 5 3
5 3 4 4 2 3 2
EOF

## test case 3
cat << EOF | try 5
1
2
3
EOF
