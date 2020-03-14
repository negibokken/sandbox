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
cat << EOF | try "COUNTER_CLOCKWISE CLOCKWISE ONLINE_BACK ON_SEGMENT ONLINE_FRONT"
0 0 2 0
5
-1 1
-1 -1
-1 0
0 0
3 0
EOF

