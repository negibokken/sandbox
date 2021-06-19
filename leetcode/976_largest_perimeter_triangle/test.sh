#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try 5
3
2 1 2
EOF

## test case 2
cat << EOF | try 0
3
1 2 1
EOF

## test case 2
cat << EOF | try 10
4
3 2 3 4
EOF

## test case 2
cat << EOF | try 8
4
3 6 2 3
EOF
