#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try "f, e, a, b, d, c, "
6 5
a b c d e f
(d, a), (b, f), (d, b), (a, f), (c, d)
EOF

