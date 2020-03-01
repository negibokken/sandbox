#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./validate`

  #actual=`echo $actual`
  #expected=`echo $expected`

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
cat << EOF | try "3 4 2 5 1 "
7
1 2 l
2 3 l
2 4 r
4 5 r
1 6 r
6 7 l
EOF
