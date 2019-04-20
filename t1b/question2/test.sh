#!/bin/bash

try() {
  expected="$1"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try *rr*r
5
error
2
EOF

## test case 2
cat << EOF | try e*e*e*
6
eleven
5
EOF

## test case 3
cat << EOF | try "******i**"
9
education
7
EOF
