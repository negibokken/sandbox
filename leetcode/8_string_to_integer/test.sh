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
cat << EOF | try 42
42
EOF

## test case 2
cat << EOF | try -42
  -42
EOF

## test case 2
cat << EOF | try 4193
4193 with words
EOF

## test case 2
cat << EOF | try 0
words and 987
EOF

## test case 2
cat << EOF | try -2147483648
-91283472332
EOF

cat << EOF | try 12345678
  0000000000012345678
EOF

cat << EOF | try -1
-000000000000001
EOF

cat << EOF | try 0
+-2
EOF

cat << EOF | try 2147483647
2147483647
EOF

cat << EOF | try 2147483646
2147483646
EOF

cat << EOF | try 2147483647
20000000000000000000
EOF
