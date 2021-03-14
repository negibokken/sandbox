#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  expected=`echo "$expected"`

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
cat << EOF | try Alaska Dad
4
Hello Alaska Dad Peace
EOF

## test case 2
cat << EOF | try ""
1
omk
EOF

## test case 2
cat << EOF | try adsdf sfd
2
adsdf sfd
EOF
