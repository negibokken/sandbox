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
cat << EOF | try 1 1 12 2 2 11 3 3 8 4 9 10 5 4 7 6 5 6
6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0
EOF

