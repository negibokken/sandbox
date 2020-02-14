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
cat << EOF | try 26
5 3
1 9
1 7
2 6
2 5
3 1
EOF

## test case 2
cat << EOF | try 25
7 4
1 1
2 1
3 1
4 6
4 5
4 5
4 5
EOF

## test case 2
cat << EOF | try 4900000016
6 5
5 1000000000
2 990000000
3 980000000
6 970000000
6 960000000
4 950000000
EOF
