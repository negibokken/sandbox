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
10 3
4 5 6
EOF

## test case 2
cat << EOF | try No
20 3
4 5 6
EOF

## test case 2
cat << EOF | try Yes
210 5
31 41 59 26 53
EOF

## test case 2
cat << EOF | try No
211 5
31 41 59 26 53
EOF
