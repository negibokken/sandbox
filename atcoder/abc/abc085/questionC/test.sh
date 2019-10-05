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
cat << EOF | try "4 0 5"
9 45000
EOF

## test case 2
cat << EOF | try "-1 -1 -1"
20 196000
EOF

## test case 2
cat << EOF | try "14 27 959"
1000 1234000
EOF

## test case 2
cat << EOF | try "2000 0 0"
2000 20000000
EOF

