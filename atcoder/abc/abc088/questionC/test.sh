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
1 0 1
2 1 2
1 0 1
EOF

## test case 2
cat << EOF | try No
2 2 2
2 1 2
2 2 2
EOF

## test case 2
cat << EOF | try Yes
0 8 8
0 8 8
0 8 8
EOF

## test case 2
cat << EOF | try No
1 8 6
2 9 7
0 7 7
EOF
