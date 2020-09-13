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
cat << EOF | try true
4
1 -1 3 -1
2 -1 -1 -1
EOF

## test case 2
cat << EOF | try false
4
1 -1 3 -1
2 3 -1 -1
EOF

## test case 2
cat << EOF | try false
2
1 0
-1 -1
EOF

## test case 2
cat << EOF | try false
6
1 -1 -1 4 -1 -1
2 -1 -1 5 -1 -1
EOF

cat << EOF | try true
4
3 -1 1 -1
-1 -1 0 -1
EOF
