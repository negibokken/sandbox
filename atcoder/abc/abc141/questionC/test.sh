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
cat << EOF | try No No Yes No No No
6 3 4
3
1
3
2
EOF

## test case 2
cat << EOF | try Yes Yes Yes Yes Yes Yes
6 5 4
3
1
3
2
EOF

## test case 2
cat << EOF | try No No No No Yes No No No Yes No
10 13 15
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
5
8
9
7
9
EOF
