#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  expected=`echo "$expected"`

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
2 2
EOF

## test case 2
cat << EOF | try 1
2 1
EOF

## test case 2
cat << EOF | try 1
1 1
EOF

## test case 2
cat << EOF | try 1
3 1
EOF

## test case 2
cat << EOF | try 2
3 2
EOF

## test case 2
cat << EOF | try 3
3 3
EOF

## test case 2
cat << EOF | try 1
4 1
EOF

## test case 2
cat << EOF | try 2
4 2
EOF

## test case 2
cat << EOF | try 3
4 3
EOF

## test case 2
cat << EOF | try 4
4 4
EOF

## test case 2
cat << EOF | try 6
10 6
EOF
