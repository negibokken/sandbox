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
cat << EOF | try "100 110 111 110"
4 3
1 2
2 3
2 4
2 10
1 100
3 1
EOF

## test case 2
cat << EOF | try "20 20 20 20 20 20"
6 2
1 2
1 3
2 4
3 6
2 5
1 10
1 10
EOF
