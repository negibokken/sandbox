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
cat << EOF | try Yes
50 100 120
EOF

## test case 2
cat << EOF | try No
500 100 1000
EOF

## test case 2
cat << EOF | try No
19 123 143
EOF

## test case 2
cat << EOF | try Yes
19 123 142
EOF
