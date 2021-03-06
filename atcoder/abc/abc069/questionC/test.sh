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
cat << EOF | try Yes
3
1 10 100
EOF

## test case 2
cat << EOF | try No
4
1 2 3 4
EOF

## test case 2
cat << EOF | try Yes
3
1 4 1
EOF

## test case 2
cat << EOF | try No
2
1 1
EOF

## test case 2
cat << EOF | try Yes
6
2 7 1 8 2 8
EOF
