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
cat << EOF | try ayb
axyb
abyxb
EOF

## test case 2
cat << EOF | try aa
aa
xayaz
EOF

## test case 2
cat << EOF | try ' '
a
z
EOF

## test case 2
cat << EOF | try bde
abdded
zbde
EOF
