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
4 5
1 2
1 3
3 2
2 4
3 4
EOF

## test case 2
cat << EOF | try 2
6 3
2 3
4 5
5 6
EOF

## test case 2
cat << EOF | try 3
5 8
5 3
2 3
2 4
5 2
5 1
1 4
4 3
1 3
EOF
