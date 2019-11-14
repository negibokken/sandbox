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
cat << EOF | try YES
rng gorilla apple
EOF

## test case 2
cat << EOF | try NO
yakiniku unagi sushi
EOF

## test case 2
cat << EOF | try YES
a a a
EOF

## test case 2
cat << EOF | try NO
aaaaaaaaab aaaaaaaaaa aaaaaaaaab
EOF
