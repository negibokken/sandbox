#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

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
cat << EOF | try 6
1 2 3
EOF

## test case 2
cat << EOF | try 42
-10 9 20 null null 15 7
EOF

## test case 2
cat << EOF | try 2
2 -1 -2
EOF

cat << EOF | try 10
-1 -2 10 -6 null -3 -6
EOF
