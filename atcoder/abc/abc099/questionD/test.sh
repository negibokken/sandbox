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
cat << EOF | try 3
2 3
0 1 1
1 0 1
1 4 0
1 2
3 3
EOF

## test case 2
cat << EOF | try 428
4 3
0 12 71
81 0 53
14 92 0
1 1 2 1
2 1 1 2
2 2 1 3
1 1 2 2
EOF
