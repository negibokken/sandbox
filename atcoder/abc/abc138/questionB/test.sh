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
cat << EOF | try 7.5
2
10 30
EOF

## test case 2
cat << EOF | try 66.66666666666667
3
200 200 200
EOF

## test case 2
cat << EOF | try 1000
1
1000
EOF
