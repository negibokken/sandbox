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
3
2 1 2
EOF

## test case 2
cat << EOF | try -1
3
2 2 2
EOF

## test case 2
cat << EOF | try 7
10
3 1 4 1 5 9 2 6 5 3
EOF

## test case 2
cat << EOF | try 0
1
1
EOF
