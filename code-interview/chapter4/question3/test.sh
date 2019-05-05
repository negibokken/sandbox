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
cat << EOF | try "depth:0,5,depth:1,2,8,depth:2,1,3,6,9,depth:3,4,7,10,"
10
1 2 3 4 5 6 7 8 9 10
EOF

## test case 2
cat << EOF | try "depth:0,4,depth:1,3,5,depth:2,6,"
4
3 4 5 6
EOF
