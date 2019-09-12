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
cat << EOF | try 520
600
300
220
420
EOF

## test case 2
cat << EOF | try 755
555
555
400
200
EOF

## test case 2
cat << EOF | try 1152
549
817
715
603
EOF
