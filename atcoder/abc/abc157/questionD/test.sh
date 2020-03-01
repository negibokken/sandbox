#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  # actual=`echo $actual`
  # expected=`echo $expected`

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
cat << EOF | try 0 1 0 1
4 4 1
2 1
1 3
3 2
3 4
4 1
EOF

## test case 2
cat << EOF | try 0 0 0 0 0
5 10 0
1 2
1 3
1 4
1 5
3 2
2 4
2 5
4 3
5 3
4 5
EOF

## test case 2
cat << EOF | try 1 3 5 4 3 3 3 3 1 0
10 9 3
10 1
6 7
8 2
2 5
8 4
7 3
10 9
6 4
5 8
2 6
7 5
3 1
EOF
