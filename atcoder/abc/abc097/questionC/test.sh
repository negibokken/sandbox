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
cat << EOF | try b
aba
4
EOF

## test case 2
cat << EOF | try andat
atcoderandatcodeer
5
EOF

## test case 2
cat << EOF | try z
z
1
EOF
