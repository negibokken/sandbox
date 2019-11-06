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
cat << EOF | try 6
abaababaab
EOF

## test case 2
cat << EOF | try 2
xxxx
EOF

## test case 3
cat << EOF | try 6
abcabcabcabc
EOF

## test case 3
cat << EOF | try 14
akasakaakasakasakaakas
EOF
