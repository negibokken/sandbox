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
cat << EOF | try 4
3 70
7 60
1 80
4 50
EOF

## test case 2
cat << EOF | try TLE
4 3
1 1000
2 4
3 1000
4 500
EOF

## test case 2
cat << EOF | try 5
5 9
25 8
5 9
4 10
1000 1000
6 1
EOF
