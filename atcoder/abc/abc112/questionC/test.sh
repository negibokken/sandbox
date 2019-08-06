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
cat << EOF | try "2 2 6"
4
2 3 5
2 1 5
1 2 5
3 2 5
EOF

## test case 2
cat << EOF | try "0 0 100"
2
0 0 100
1 1 98
EOF

## test case 2
cat << EOF | try "100 0 193"
3
99 1 191
100 1 192
99 0 192
EOF
