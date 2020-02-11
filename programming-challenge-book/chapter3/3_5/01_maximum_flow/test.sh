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
cat << EOF | try 11
7
0 4
0 1 10
0 2 2
1 2 6
1 3 6
3 2 3
3 4 8
2 4 5
EOF

## test case 1
cat << EOF | try 9
7
0 4
0 1 5
0 2 8
2 1 2
1 3 3
2 3 5
2 4 3
3 4 6
EOF

