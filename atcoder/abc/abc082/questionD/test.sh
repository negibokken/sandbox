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
FTFFTFFF
4 2
EOF

## test case 2
cat << EOF | try Yes
FTFFTFFF
-2 -2
EOF

## test case 2
cat << EOF | try No
FF
1 0
EOF

## test case 2
cat << EOF | try No
TF
1 0
EOF

## test case 2
cat << EOF | try Yes
FFTTFF
0 0
EOF

## test case 2
cat << EOF | try No
TTTT
1 0
EOF
