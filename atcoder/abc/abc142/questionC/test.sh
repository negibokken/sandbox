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
cat << EOF | try "3 1 2"
3
2 3 1
EOF

## test case 2
cat << EOF | try "1 2 3 4 5"
5
1 2 3 4 5
EOF

## test case 2
cat << EOF | try "8 2 4 5 6 7 3 1"
8
8 2 7 3 4 5 6 1
EOF
