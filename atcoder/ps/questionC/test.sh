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
cat << EOF | try No
2 3 9
EOF

## test case 2
cat << EOF | try Yes
2 3 10
EOF

## test case 2
cat << EOF | try No
1000000000 1000000000 1000000000
EOF

## test case 2
cat << EOF | try Yes
50000000 500000000 1000000000
EOF

## test case 2
cat << EOF | try No
1 1 1
EOF

## test case 2
cat << EOF | try No
1 1 2
EOF

## test case 2
cat << EOF | try No
1 1 3
EOF

## test case 2
cat << EOF | try Yes
1 1 5
EOF

## test case 2
cat << EOF | try Yes
1000000000 1 1000140625
EOF

## test case 2
cat << EOF | try Yes
249999999 250000000 999999998
EOF
