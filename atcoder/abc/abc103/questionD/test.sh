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
5 2
1 4
2 5
EOF

## test case 2
cat << EOF | try 2
9 5
1 8
2 7
3 5
4 6
7 9
EOF

## test case 2
cat << EOF | try 4
5 10
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
EOF
