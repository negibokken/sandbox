#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  # actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try 4
4 5
3 2 4 1
EOF

## test case 2
cat << EOF | try 2
6 727202214173249351
6 5 2 5 3 2
EOF

## test case 1
cat << EOF | try 3
4 2
2 3 4 1
EOF

## test case 1
cat << EOF | try 1
4 0
2 3 4 1
EOF

## test case 1
cat << EOF | try 2
4 5
2 3 4 1
EOF
