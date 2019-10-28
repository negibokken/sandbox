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
cat << EOF | try 4
1
10
2
EOF

## test case 2
cat << EOF | try 12
2
9
3 6
EOF

## test case 2
cat << EOF | try 74
5
20
11 12 9 17 12
EOF
