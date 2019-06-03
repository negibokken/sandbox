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
2 2
2 1 2
1 2
0 1
EOF

## test case 2
cat << EOF | try 0
2 3
2 1 2
1 1
1 2
0 0 1
EOF

cat << EOF | try 8
5 2
3 1 2 5
2 2 3
1 0
EOF
