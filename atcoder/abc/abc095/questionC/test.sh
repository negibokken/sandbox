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
cat << EOF | try 7900
1500 2000 1600 3 2
EOF

## test case 2
cat << EOF | try 8500
1500 2000 1900 3 2
EOF

## test case 2
cat << EOF | try 100000000
1500 2000 500 90000 100000
EOF
