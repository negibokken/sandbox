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
cat << EOF | try "-1 1 -1 0"
0 0 0 1
EOF

## test case 2
cat << EOF | try "3 10 -1 7"
2 3 6 6
EOF

## test case 1
cat << EOF | try "-126 -64 -36 -131"
31 -41 -59 26
EOF

