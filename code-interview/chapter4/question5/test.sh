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
7 1
1 2 3 4 5 6 7
EOF

## test case 1
cat << EOF | try 3
7 2
1 2 3 4 5 6 7
EOF

## test case 1
cat << EOF | try 4
7 3
1 2 3 4 5 6 7
EOF

## test case 1
cat << EOF | try 5
7 4
1 2 3 4 5 6 7
EOF

## test case 1
cat << EOF | try 6
7 5
1 2 3 4 5 6 7
EOF

## test case 1
cat << EOF | try 7
7 6
1 2 3 4 5 6 7
EOF

## test case 1
cat << EOF | try NULL
7 7
1 2 3 4 5 6 7
EOF

