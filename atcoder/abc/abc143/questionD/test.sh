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
cat << EOF | try 1
4
3 4 2 1
EOF

## test case 2
cat << EOF | try 0
3
1 1000 1
EOF

cat << EOF | try 23
7
218 786 704 233 645 728 389
EOF
