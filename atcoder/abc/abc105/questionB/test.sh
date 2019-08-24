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
11
EOF

## test case 2
cat << EOF | try Yes
40
EOF

## test case 2
cat << EOF | try No
3
EOF

# for i in {1..100}; do
# cat << EOF | try
# $i
# EOF
# done

