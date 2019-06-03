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
cat << EOF | try 17
7 9
0 2 1
1 2 2
2 3 3
1 4 10
4 5 5
2 5 7
3 5 1
3 6 5
5 6 8
EOF

