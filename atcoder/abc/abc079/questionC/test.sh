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
cat << EOF | try "1+2+2+2=7"
1222
EOF

## test case 2
cat << EOF | try "0-2+9+0=7"
0290
EOF

## test case 2
cat << EOF | try "3-2+4+2=7"
3242
EOF
