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
cat << EOF | try No
3 3
0 1
1 2
2 0
EOF

## test case 2
cat << EOF | try Yes
4 4
0 1
0 3
1 2
2 3
EOF
