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
cat << EOF | try "12 8 10"
3
3 5 -1
EOF

## test case 2
cat << EOF | try "4 4 4 2 4"
5
1 1 1 2 0
EOF

## test case 2
cat << EOF | try "21630 21630 19932 8924 21630 19288"
6
-679 -2409 -3258 3095 -3291 -4462
EOF
