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
cat << EOF | try 1
2 3 -10
1 2 3
3 2 1
1 2 2
2 5
4 9
2 4
EOF

## test case 2
cat << EOF | try 2
5 2 -4
-2 5
100 41
100 40
-3 0
-6 -2
18 -13
EOF

cat << EOF | try 0
3 3 0
100 -100 0
0 100 100
100 100 100
-100 100 100
EOF
