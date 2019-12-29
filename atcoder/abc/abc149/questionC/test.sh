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
cat << EOF | try 23
20
EOF

## test case 2
cat << EOF | try 2
2
EOF

## test case 2
cat << EOF | try 100003
99992
EOF

cat << EOF | try 3467
3467
EOF


cat << EOF | try 99989
99989
EOF
