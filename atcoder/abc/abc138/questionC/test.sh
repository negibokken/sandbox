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
cat << EOF | try 3.5
2
3 4
EOF

## test case 2
cat << EOF | try 375
3
500 300 200
EOF

cat << EOF | try 138
5
138 138 138 138 138
EOF
