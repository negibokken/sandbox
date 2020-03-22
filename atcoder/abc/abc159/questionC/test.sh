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
cat << EOF | try 1.000000000000
3
EOF

## test case 2
cat << EOF | try 36926037.000000000000
999
EOF

cat << EOF | try 2.370370370370
4
EOF

cat << EOF | try 2.370370370370
5
EOF

cat << EOF | try 37037037.037
1000
EOF
