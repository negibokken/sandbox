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
cat << EOF | try Left
3 8 7 1
EOF

## test case 2
cat << EOF | try Balanced
3 4 5 2
EOF

## test case 2
cat << EOF | try Right
1 7 6 4
EOF
