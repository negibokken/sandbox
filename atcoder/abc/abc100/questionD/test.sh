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
cat << EOF | try 56
5 3
3 1 4
1 5 9
2 6 5
3 5 8
9 7 9
EOF

## test case 2
cat << EOF | try 54
5 3
1 -2 3
-4 5 -6
7 -8 -9
-10 11 -12
13 -14 15
EOF

## test case 2
cat << EOF | try 638
10 5
10 -80 21
23 8 38
-94 28 11
-26 -2 18
-69 72 79
-26 -86 -54
-72 -50 59
21 65 -32
40 -94 87
-62 18 82
EOF

## test case 2
cat << EOF | try 30000000000
3 2
2000000000 -9000000000 4000000000
7000000000 -5000000000 3000000000
6000000000 -1000000000 8000000000
EOF
