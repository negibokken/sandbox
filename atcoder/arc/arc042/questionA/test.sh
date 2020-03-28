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
cat << EOF | try "1 3 2"
3 3
2
3
1
EOF

## test case 2
cat << EOF | try "1 2 3"
3 3
1
1
1
EOF

## test case 2
cat << EOF | try "3 5 6 2 9 1 4 7 8 10"
10 10
3
1
4
1
5
9
2
6
5
3
EOF

