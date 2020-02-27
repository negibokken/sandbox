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
cat << EOF | try "0 1 2 3 4 5 6 7 8"
9 0
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
EOF


## test case 1
cat << EOF | try "2 1 3 0 6 5 7 4 8"
9 1
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
EOF

## test case 1
cat << EOF | try "2 3 1 6 7 5 8 4 0"
9 2
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1
EOF

