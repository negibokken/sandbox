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
cat << EOF | try "2 1"
2 2
2 0
0 0
-1 0
1 0
EOF

## test case 2
cat << EOF | try "3 1 2"
3 4
10 10
-10 -10
3 3
1 2
2 3
3 5
3 5
EOF

## test case 2
cat << EOF | try "5 4 3 2 1"
5 5
-100000000 -100000000
-100000000 100000000
100000000 -100000000
100000000 100000000
0 0
0 0
100000000 100000000
100000000 -100000000
-100000000 100000000
-100000000 -100000000
EOF
