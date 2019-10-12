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
cat << EOF | try 1
5
WEEWW
EOF


## test case 2
cat << EOF | try 4
12
WEWEWEEEWWWE
EOF

## test case 2
cat << EOF | try 3
8
WWWWWEEE
EOF

## test case 2
cat << EOF | try 0
8
EWWWWWWW
EOF

## test case 2
cat << EOF | try 0
8
EEEEEEEW
EOF

## test case 2
cat << EOF | try 1
4
WEEW
EOF
