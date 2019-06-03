#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try "0\n0\n1"
3
1 2 2
2 3 1
EOF

## test case 2
cat << EOF | try  2 3 3 4
5
2 5 2
2 3 10
1 3 8
3 4 2
EOF
