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
cat << EOF | try "1 2 3 4 5 6 "
6
5 2 4 6 1 3
EOF

## test case 1
cat << EOF | try "1 2 3 4 5 6 "
6
2 5 4 1 3 6
EOF
