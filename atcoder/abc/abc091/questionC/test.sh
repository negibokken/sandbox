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
3
2 0
3 1
1 3
4 2
0 4
5 5
EOF

## test case 2
cat << EOF | try 2
3
0 0
1 1
5 2
2 3
3 4
4 5
EOF

## test case 2
cat << EOF | try 0
2
2 2
3 3
0 0
1 1
EOF

## test case 2
cat << EOF | try 5
5
0 0
7 3
2 2
4 8
1 6
8 5
6 9
5 4
9 1
3 7
EOF

## test case 2
cat << EOF | try 4
5
0 0
1 1
5 5
6 6
7 7
2 2
3 3
4 4
8 8
9 9
EOF
