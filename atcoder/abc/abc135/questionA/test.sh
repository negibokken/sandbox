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
cat << EOF | try 9
2 16
EOF

## test case 2
cat << EOF | try IMPOSSIBLE
0 3
EOF

## test case 3
cat << EOF | try 549034394
998244353 99824435
EOF
