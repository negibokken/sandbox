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
cat << EOF | try "2 1 2"
3
1 2
2 3
EOF

## test case 2
cat << EOF | try "4 1 2 3 4 1 1 2"
8
1 2
2 3
2 4
2 5
4 7
5 6
6 8
EOF

## test case 2
cat << EOF | try "5 1 2 3 4 5"
6
1 2
1 3
1 4
1 5
1 6
EOF
