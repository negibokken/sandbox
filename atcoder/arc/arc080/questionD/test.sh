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
cat << EOF | try 1 1 2 3
2 2
3
2 1 1
EOF

## test case 2
cat << EOF | try 1 4 4 4 3 2 5 4 5 3 2 5 5 5 3
3 5
5
1 2 3 4 5
EOF

## test case 2
cat << EOF | try 1
1 1
1
1
EOF
