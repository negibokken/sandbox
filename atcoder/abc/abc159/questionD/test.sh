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
cat << EOF | try 2 2 3 2 3
5
1 1 2 1 2
EOF

## test case 2
cat << EOF | try 0 0 0 0
4
1 2 3 4
EOF

## test case 2
cat << EOF | try 6 6 6 6 6
5
3 3 3 3 3
EOF

## test case 2
cat << EOF | try 0 0 0 0 0
5
1 2 3 4 5
EOF

## test case 2
cat << EOF | try 5 7 5 7 7 5 7 5
8
1 2 1 4 2 1 4 1
EOF

## test case 2
cat << EOF | try 0
1
1
EOF

## test case 2
cat << EOF | try 0 0
2
1 2
EOF

## test case 2
cat << EOF | try 0 0
2
2 2
EOF

## test case 2
cat << EOF | try 1 1 1
3
2 2 2
EOF
