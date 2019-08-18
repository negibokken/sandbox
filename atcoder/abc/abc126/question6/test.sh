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
cat << EOF | try "0 0 1 1"
1 0
EOF

## test case 2
cat << EOF | try -1
1 1
EOF

## test case 2
cat << EOF | try -1
5 58
EOF

## test case 1
cat << EOF | try
5 30
EOF
