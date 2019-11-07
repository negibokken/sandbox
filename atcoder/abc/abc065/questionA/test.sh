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
cat << EOF | try safe
4 3 6
EOF

## test case 2
cat << EOF | try delicious
6 5 1
EOF

## test case 2
cat << EOF | try dangerous
3 7 12
EOF
