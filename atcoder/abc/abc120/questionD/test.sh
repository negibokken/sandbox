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
cat << EOF | try 0 0 4 5 6
4 5
1 2
3 4
1 3
2 3
1 4
EOF

## test case 2
cat << EOF | try 8 9 12 14 15
6 5
2 3
1 2
5 6
3 4
4 5
EOF

## test case 2
cat << EOF | try 1
2 1
1 2
EOF

## test case 2
cat << EOF | try 5 9 12 14 15
6 5
1 2
2 3
3 4
4 5
5 6
EOF

## test case 2
cat << EOF | try 11 15 18 20 21
7 5
1 2
2 3
3 4
4 5
5 6
EOF
