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
cat << EOF | try 2
4 10
6 1 2 7
EOF

## test case 2
cat << EOF | try 3
3 5
3 3 3
EOF

# test case 2
cat << EOF | try 36
10 53462
103 35322 232 342 21099 90000 18843 9010 35221 19352
EOF
