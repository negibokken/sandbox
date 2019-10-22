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
cat << EOF | try 3
2
1 5
2 4
3 6
EOF

## test case 2
cat << EOF | try 27
3
1 1 1
2 2 2
3 3 3
EOF

## test case 2
cat << EOF | try 87
6
3 14 159 2 6 53
58 9 79 323 84 6
2643 383 2 79 50 288
EOF

## test case 2
cat << EOF | try 0
3
2 2 2
2 2 2
3 3 3
EOF

## test case 2
cat << EOF | try 9
3
1 2 2
2 2 2
3 3 3
EOF

## test case 2
cat << EOF | try 15
4
1 1 2 4
3 3 4 5
3 3 4 5
EOF

## test case 2
cat << EOF | try 6
4
1 1 2 4
3 3 4 5
2 3 3 4
EOF

## test case 2
cat << EOF | try 0
4
2000 1 1 4
3 3 4 5
2 3 3 2
EOF

