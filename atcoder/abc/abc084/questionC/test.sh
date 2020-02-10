#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

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
cat << EOF | try "12 11 0"
3
6 5 1
1 10 1
EOF

## test case 2
cat << EOF | try "187 167 101 0"
4
12 24 6
52 16 4
99 2 2
EOF

## test case 2
cat << EOF | try "4162 4162 4162 0"
4
12 13 1
44 17 17
66 4096 64
EOF
