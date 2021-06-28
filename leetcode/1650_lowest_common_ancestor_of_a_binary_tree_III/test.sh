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
cat << EOF | try 3
11
3 5 1 6 2 0 8 null null 7 4
5 1
EOF

## test case 2
cat << EOF | try 5
11
3 5 1 6 2 0 8 null null 7 4
5 4
EOF

## test case 2
cat << EOF | try 1
2
1 2
1 2
EOF
