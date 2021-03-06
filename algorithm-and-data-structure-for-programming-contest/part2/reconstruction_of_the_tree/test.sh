#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

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
cat << EOF | try "3 4 2 5 1"
5
1 2 3 4 5
3 2 4 1 5
EOF


## test case 1
cat << EOF | try "3 5 4 2 7 6 1"
7
1 2 3 4 5 6 7
3 2 4 5 1 7 6
EOF

