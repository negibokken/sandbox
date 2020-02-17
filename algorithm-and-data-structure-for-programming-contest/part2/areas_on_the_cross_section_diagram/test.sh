#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  echo "$input"
  actual=`echo "$input" | ./main`

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
cat << \EOF | try 35
\\///\_/\/\\\\/_/\\///__\\\_\\/_\/_/\
EOF

