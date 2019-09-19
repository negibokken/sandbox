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
cat << EOF | try Yes
RUDLUDR
EOF

## test case 2
cat << EOF | try No
DULL
EOF

## test case 2
cat << EOF | try Yes
UUUUUUUUUUUUUUU
EOF

## test case 2
cat << EOF | try No
ULURU
EOF

## test case 2
cat << EOF | try Yes
RDULULDURURLRDULRLR
EOF
