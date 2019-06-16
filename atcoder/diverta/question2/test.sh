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
cat << EOF | try 1
2
1 1
2 2
EOF

## test case 2
cat << EOF | try 1
3
1 4
4 6
7 8
EOF

## test case 2
cat << EOF | try 2
4
1 1
1 2
2 1
2 2
EOF
