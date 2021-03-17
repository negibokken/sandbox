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
cat << EOF | try null true true false false false true
7
Logger shouldPrintMessage shouldPrintMessage shouldPrintMessage shouldPrintMessage shouldPrintMessage shouldPrintMessage
0 0
1 foo
2 bar
3 foo
8 bar
10 foo
11 foo
EOF

