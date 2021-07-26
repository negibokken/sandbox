#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

  actual=`echo "$actual"`
  actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try "[[1, 5], [6, 9]]"
2
1 3
6 9
2 5
EOF

## test case 2
cat << EOF | try "[[1, 2], [3, 10], [12, 16]]"
5
1 2
3 5
6 7
8 10
12 16
4 8
EOF

cat << EOF | try "[[5, 7]]"
0
5 7
EOF

cat << EOF | try "[[1, 5]]"
1
1 5
2 3
EOF

cat << EOF | try "[[1, 7]]"
1
1 5
2 7
EOF

cat << EOF | try "[[1, 5]]"
1
2 5
1 3
EOF
