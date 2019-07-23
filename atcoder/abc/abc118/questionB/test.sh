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
3 4
2 1 3
3 1 2 3
2 3 2
EOF
## test case 2
cat << EOF | try 0
5 5
4 2 3 4 5
4 1 3 4 5
4 1 2 4 5
4 1 2 3 5
4 1 2 3 4
EOF

## test case 3
cat << EOF | try 3
1 30
3 5 10 30
EOF
