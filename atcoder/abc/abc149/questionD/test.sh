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
cat << EOF | try 27
5 2
8 7 6
rsrpr
EOF

## test case 2
cat << EOF | try 211
7 1
100 10 1
ssssppr
EOF

## test case 2
cat << EOF | try 4996
30 5
325 234 123
rspsspspsrpspsppprpsprpssprpsr
EOF
