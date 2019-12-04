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
cat << EOF | try GREATER
36
24
EOF

## test case 2
cat << EOF | try LESS
850
3777
EOF

## test case 2
cat << EOF | try LESS
9720246
22516266
EOF

## test case 2
cat << EOF | try LESS
123456789012345678901234567890
234567890123456789012345678901
EOF
