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
cat << EOF | try "4 2 1 3"
4
1 2 3 4
EOF

## test case 2
cat << EOF | try "3 1 2"
3
1 2 3
EOF

## test case 2
cat << EOF | try "1000000000"
1
1000000000
EOF

## test case 2
cat << EOF | try "0 6 6 0 7 7"
6
0 6 7 6 7 0
EOF
