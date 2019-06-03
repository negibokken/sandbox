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
cat << EOF | try
5
1 2
2 3
3 4
4 5
1 2 3 4 5
EOF

## test case 2
cat << EOF | try
5
1 2
1 3
1 4
1 5
3141 59 26 53 59
EOF
