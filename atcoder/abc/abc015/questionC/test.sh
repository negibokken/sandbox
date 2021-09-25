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
cat << EOF | try Found
3 4
1 3 5 17
2 4 2 3
1 3 2 9
EOF

## test case 2
cat << EOF | try Nothing
5 3
89 62 15
44 36 17
4 24 24
25 98 99
66 33 57
EOF
