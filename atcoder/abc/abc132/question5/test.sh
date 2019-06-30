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
cat << EOF | try 2
4 4
1 2
2 3
3 4
4 1
1 3
EOF

## test case 2
cat << EOF | try -1
3 3
1 2
2 3
3 1
1 2
EOF

## test case 2
cat << EOF | try -1
2 0
1 2
EOF

## test case 2
cat << EOF | try 2
6 8
1 2
2 3
3 4
4 5
5 1
1 4
1 5
4 6
1 6
EOF
