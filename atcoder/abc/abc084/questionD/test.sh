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
1
3 7
EOF

## test case 2
cat << EOF | try "1 0 0 1"
4
13 13
7 11
7 11
2017 2017
EOF

## test case 2
cat << EOF | try "4 4 1 1 1 2"
6
1 53
13 91
37 55
19 51
73 91
13 49
EOF

## test case 2
cat << EOF | try "2"
1
5 13
EOF
