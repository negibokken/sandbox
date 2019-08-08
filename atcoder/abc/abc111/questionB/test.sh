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
cat << EOF | try 111
111
EOF

## test case 2
cat << EOF | try 222
112
EOF

## test case 2
cat << EOF | try 777
750
EOF

## test case 2
cat << EOF | try 888
778
EOF

## test case 2
cat << EOF | try 888
787
EOF

## test case 2
cat << EOF | try 888
787
EOF

## test case 2
cat << EOF | try 777
768
EOF
