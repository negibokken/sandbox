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
cat << EOF | try "[1] [3 2 4] [5 6]"
8
1 -1 3 2 4 -1 5 6
EOF
exit
## test case 2
cat << EOF | try "[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]"
25
1 -1 2 3 4 5 -1 -1 6 7 -1 8 -1 9 10 -1 -1 11 -1 12 -1 13 -1 -1 14
EOF
