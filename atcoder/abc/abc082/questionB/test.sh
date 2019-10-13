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
cat << EOF | try Yes
yx
axy
EOF

## test case 2
cat << EOF | try Yes
ratcode
atlas
EOF

## test case 2
cat << EOF | try No
cd
abc
EOF

## test case 2
cat << EOF | try No
zzz
zzz
EOF
