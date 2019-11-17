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
cat << EOF | try 2
3 3
EOF

## test case 2
cat << EOF | try 0
2 2
EOF

## test case 2
cat << EOF | try 1
2 1
EOF

cat << EOF | try 151840682
999999 999999
EOF

