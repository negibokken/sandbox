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
cat << EOF | try 0
2 2
EOF

## test case 2
cat << EOF | try 5
1 7
EOF

## test case 2
cat << EOF | try 496080
314 1592
EOF
