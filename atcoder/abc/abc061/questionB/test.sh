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
cat << EOF | try 1 3 3 3 4 5 6
4 3
1 2
2 3
1 4
EOF

## test case 2
cat << EOF | try 2 3 3 4
2 5
1 2
2 1
1 2
2 1
1 2
EOF

cat << EOF | try 2 3 3 4
8 8
1 2
3 4
1 5
2 8
3 7
5 2
4 1
6 8
EOF
