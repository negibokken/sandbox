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
cat << EOF | try CDEZAB
2
ABCXYZ
EOF

## test case 2
cat << EOF | try ABCXYZ
0 ABCXYZ
EOF

## test case 2
cat << EOF | try NOPQRSTUVWXYZABCDEFGHIJKLM
13
ABCDEFGHIJKLMNOPQRSTUVWXYZ
EOF
