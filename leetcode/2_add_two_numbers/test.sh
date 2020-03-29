#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo $actual`
  expected=`echo $expected`

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
cat << EOF | try 708
3 3
2 4 3
5 6 4
EOF

## test case 2
cat << EOF | try 74
2 1
2 4
5
EOF

cat << EOF | try 701
2 2
2 9
5 1
EOF
