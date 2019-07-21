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
cat << EOF | try 2
5
2
1
4
5
3
EOF

## test case 2
cat << EOF | try 4
4
0
0
0
0
EOF

## test case 2
cat << EOF | try 1
4
1
3
4
5
EOF
