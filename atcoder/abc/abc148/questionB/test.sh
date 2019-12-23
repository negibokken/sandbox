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
cat << EOF | try icpc
2
ip cc
EOF

## test case 2
cat << EOF | try humuhumunukunuku
8
hmhmnknk uuuuuuuu
EOF

## test case 2
cat << EOF | try aaaaaaaaaa
5
aaaaa aaaaa
EOF
