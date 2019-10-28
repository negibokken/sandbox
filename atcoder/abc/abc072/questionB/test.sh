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
cat << EOF | try acdr
atcoder
EOF

## test case 2
cat << EOF | try aa
aaaa
EOF

## test case 2
cat << EOF | try z
z
EOF

## test case 2
cat << EOF | try fkoaaauh
fukuokayamaguchi
EOF
