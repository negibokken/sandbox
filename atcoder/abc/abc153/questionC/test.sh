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
cat << EOF | try 5
3 1
4 1 5
EOF


## test case 2
cat << EOF | try 0
8 9
7 9 3 2 3 8 4 6
EOF

## test case 2
cat << EOF | try 3000000000
3 0
1000000000 1000000000 1000000000
EOF
