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
cat << EOF | try 1
3 2
1 2
5 5
-2 8
EOF

## test case 2
cat << EOF | try  2
3 4
-3 7 8 2
-12 1 10 2
-2 8 9 3
EOF

## test case 2
cat << EOF | try  10
5 1
1
2
3
4
5
EOF
