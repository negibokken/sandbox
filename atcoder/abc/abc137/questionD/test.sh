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
cat << EOF | try 5
3 4
4 3
4 1
2 2
EOF

## test case 2
cat << EOF | try 10
5 3
1 2
1 3
1 4
2 1
2 3
EOF

## test case 2
cat << EOF | try 0
1 1
2 1
EOF
