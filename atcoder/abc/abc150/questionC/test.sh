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
cat << EOF | try 3
3
1 3 2
3 1 2
EOF


## test case 2
cat << EOF | try 17517
8
7 3 5 4 2 1 6 8
3 8 2 5 4 6 7 1
EOF

## test case 2
cat << EOF | try 0
3
1 2 3
1 2 3
EOF
