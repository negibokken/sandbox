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
2 4 6
EOF

## test case 2
cat << EOF | try NO
2 5 6
EOF

## test case 2
cat << EOF | try YES
3 2 1
EOF
