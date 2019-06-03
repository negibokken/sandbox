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
cat << EOF | try 14
3 2
5 1 4
2 3
1 5
EOF

## test case 2
cat << EOF | try 338
10 3
1 8 5 7 100 4 52 33 13 5
3 10
4 30
1 4
EOF

## test case 3
cat << EOF | try 300
3 2
100 100 100
3 99
3 99
EOF

## test case 4
cat << EOF | try 10000000001
11 3
1 1 1 1 1 1 1 1 1 1 1
3 1000000000
4 1000000000
3 1000000000
EOF


