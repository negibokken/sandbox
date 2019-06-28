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
cat << EOF | try "5.00 10.00 "
2 1
10 5
1
90
EOF

## test case 2
cat << EOF | try "-10.00 5.00 -5.00 10.00 "
3 2
5 5  5
1 2
270 90
EOF
