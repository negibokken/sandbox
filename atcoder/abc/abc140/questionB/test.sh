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
cat << EOF | try 14
3
3 1 2
2 5 4
3 6
EOF

## test case 2
cat << EOF | try 74
4
2 3 4 1
13 5 8 24
45 9 15
EOF

## test case 2
cat << EOF | try 150
2
1 2
50 50
50
EOF
