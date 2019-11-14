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
cat << EOF | try YES
7 5 1
EOF

## test case 2
cat << EOF | try NO
2 2 1
EOF

## test case 2
cat << EOF | try YES
1 100 97
EOF

## test case 2
cat << EOF | try YES
40 98 58
EOF

## test case 2
cat << EOF | try NO
77 42 36
EOF
