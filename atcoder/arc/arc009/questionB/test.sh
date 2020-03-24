#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo $actual`
  expected=`echo $expected`

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
cat << EOF | try 8 1 3 5 4 9 7 6 2 10
0 8 1 3 5 4 9 7 6 2
10
1
2
3
4
5
6
7
8
9
10
EOF

## test case 2
cat << EOF | try 74392 98738462 13467932
0 9 8 7 6 5 4 3 2 1
3
98738462
13467932
74392
EOF

## test case 2
cat << EOF | try 43 643 909 1234
0 1 2 3 4 5 6 7 8 9
4
643
1234
43
909
EOF

## test case 2
cat << EOF | try 333 333
0 7 4 3 9 5 6 2 1 8
2
333
333
EOF

## test case 2
cat << EOF | try 10
0 2 4 6 8 1 3 5 7 9
1
10
EOF

