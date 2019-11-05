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
cat << EOF | try 12
5 3
1 2 3 4 5
EOF

cat << EOF | try 386
15 14
50 26 27 21 41 7 42 35 7 5 5 36 39 1 45
EOF
