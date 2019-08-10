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
cat << EOF | try -10
-13 3
EOF

## test case 2
cat << EOF | try 34
1 -33
EOF

## test case 2
cat << EOF | try 39
13 3
EOF
