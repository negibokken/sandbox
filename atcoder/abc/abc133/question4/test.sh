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
cat << EOF | try "4 0 4"
3
2 2 4
EOF

## test case 2
cat << EOF | try "2 4 12 2 8"
5
3 8 7 5 5
EOF

## test case 2
cat << EOF | try "0 2000000000 0"
3
1000000000 1000000000 0
EOF
