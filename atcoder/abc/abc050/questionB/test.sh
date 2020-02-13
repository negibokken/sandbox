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
cat << EOF | try 6 9
3
2 1 4
2
1 1
2 3
EOF

## test case 2
cat << EOF | try 19 25 30
5
7 2 3 8 5
3
4 2
1 7
4 13
EOF
