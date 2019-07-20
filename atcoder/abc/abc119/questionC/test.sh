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
cat << EOF | try 23
5 100 90 80
98
40
30
21
80
EOF

## test case 2
cat << EOF | try 0
8 100 90 80
100
100
90
90
90
80
80
80
EOF

## test case 2
cat << EOF | try 243
8 1000 800 100
300
333
400
444
500
555
600
666
EOF
