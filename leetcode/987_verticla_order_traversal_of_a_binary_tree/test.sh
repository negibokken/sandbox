#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  expected=`echo "$expected"`

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
cat << EOF | try [[9],[3,15],[20],[7]]
7
3 9 20 -1 -1 15 7
EOF

## test case 2
cat << EOF | try [[4],[2],[1,5,6],[3],[7]]
7
1 2 3 4 5 6 7
EOF

cat << EOF | try [[4,10,11],[3,6,7],[2,5,8,9],[0],[1]]
17
0 2 1 3 -1 -1 -1 4 5 -1 7 6 -1 10 8 11 9
EOF

cat << EOF | try [[4,10,11],[3,6,7],[2,5,8,9],[0],[1]]
17
0 2 1 3 -1 -1 -1 4 5 -1 7 6 -1 10 8 11 9
EOF
