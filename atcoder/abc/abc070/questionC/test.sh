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
cat << EOF | try 6
2
2
3
EOF

## test case 2
cat << EOF | try 1000000000000000000
5
2
5
10
1000000000000000000
1000000000000000000
EOF
