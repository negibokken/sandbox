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
1 10
3 5
EOF

## test case 2
cat << EOF | try 2
2 10
3 5
2 6
EOF

## test case 2
cat << EOF | try 860000004
4 1000000000
1 1
1 10000000
1 30000000
1 99999999
EOF

## test case 2
cat << EOF | try 9
5 500
35 44
28 83
46 62
31 79
40 43
EOF
