#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  expected=`echo "$expected"`

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
cat << EOF | try 500
1000 0
2
10-20-30
15-24-32
EOF

## test case 2
cat << EOF | try 0
1000 0
2
10
9
EOF

## test case 2
cat << EOF | try 239
100 20
8
40-50-60
37-48-55
100-48-50
105-48-47
110-50-52
110-50-52
110-51-54
109-49-53
EOF
