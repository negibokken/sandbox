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
cat << EOF | try Yes
2
3 1 2
6 1 1
EOF

## test case 2
cat << EOF | try No
1
2 100 100
EOF

## test case 2
cat << EOF | try No
2
5 1 1
100 1 1
EOF

