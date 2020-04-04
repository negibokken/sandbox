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
cat << EOF | try Yes
4 1
5 4 2 1
EOF


## test case 2
cat << EOF | try No
3 2
380 19 1
EOF

## test case 2
cat << EOF | try Yes
12 3
4 56 78 901 2 345 67 890 123 45 6 789
EOF
