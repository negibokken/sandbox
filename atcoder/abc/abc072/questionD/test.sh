#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    # echo "$input => $actual"
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 2
5
1 4 3 5 2
EOF

## test case 2
cat << EOF | try 1
2
1 2
EOF

## test case 3
cat << EOF | try 0
2
2 1
EOF

## test case 3
cat << EOF | try 3
9
1 2 4 9 5 8 7 3 6
EOF
