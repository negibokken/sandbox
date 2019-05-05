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
cat << EOF | try "1 2 3 4 5 6 7 "
7
1 2 3 4 5 6 7
EOF

## test case 2
cat << EOF | try  "2 3 4 5 "
4
2 3 4 5
EOF
