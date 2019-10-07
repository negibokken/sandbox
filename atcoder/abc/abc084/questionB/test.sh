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
3 4
269-6650
EOF

## test case 2
cat << EOF | try No
1 1
---
EOF

## test case 2
cat << EOF | try No
1 2
7444
EOF

## test case 1
cat << EOF | try No
3 4
269-66508
EOF

## test case 1
cat << EOF | try Yes
3 5
269-66508
EOF

## test case 1
cat << EOF | try Yes
5 5
00269-66508
EOF

## test case 1
cat << EOF | try No
5 5
00269-665080
EOF

## test case 1
cat << EOF | try No
5 5
00269*665080
EOF

## test case 1
cat << EOF | try No
5 5
00269-6650A
EOF
