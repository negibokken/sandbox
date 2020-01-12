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
cat << EOF | try 2 2
2 5
1 WA
1 AC
2 WA
2 AC
2 WA
EOF

## test case 2
cat << EOF | try 1 0
100000 3
7777 AC
7777 AC
7777 AC
EOF

## test case 2
cat << EOF | try 0 0
6 0
EOF
