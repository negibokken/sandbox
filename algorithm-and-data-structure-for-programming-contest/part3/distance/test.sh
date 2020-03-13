#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo $actual`
  expected=`echo $expected`

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
cat << EOF | try "1.0000000000 1.4142135624 0.0000000000"
3
0 0 1 0 0 1 1 1
0 0 1 0 2 1 1 2
-1 0 1 0 0 1 0 -1
EOF

