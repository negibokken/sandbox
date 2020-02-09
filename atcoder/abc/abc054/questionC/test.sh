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
3 3
1 2
1 3
2 3
EOF

## test case 2
cat << EOF | try 1
7 7
1 3
2 7
3 4
4 5
4 6
5 6
6 7
EOF
