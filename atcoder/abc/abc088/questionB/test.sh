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
2
3 1
EOF

## test case 2
cat << EOF | try 5
3
2 7 4
EOF

## test case 2
cat << EOF | try 18
4
20 18 2 18
EOF
