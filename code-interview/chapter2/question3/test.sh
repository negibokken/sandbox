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
cat << EOF | try  a b c d f g h i j k
11 e
a b c d e f g h i j k
EOF

## test case 2
cat << EOF | try a b c d e f g h i
10 e
a b c d e e f g h i
EOF

## test case 3
cat << EOF | try a b c d f g h i
8 e
a b c d f g h i
EOF

