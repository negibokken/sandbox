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
azzel
apple
EOF

## test case 2
cat << EOF | try No
chokudai
redcoder
EOF

## test case 2
cat << EOF | try Yes
abcdefghijklmnopqrstuvwxyz
ibyhqfrekavclxjstdwgpzmonu
EOF
