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
cat << EOF | try No
4
hoge
english
hoge
enigma
EOF

## test case 2
cat << EOF | try Yes
9
basic
c
cpp
php
python
nadesico
ocaml
lua
assembly
EOF

## test case 3
cat << EOF | try No
8
a
aa
aaa
aaaa
aaaaa
aaaaaa
aaa
aaaaaaa
EOF

## test case 3
cat << EOF | try No
3
abc
arc
agc
EOF
