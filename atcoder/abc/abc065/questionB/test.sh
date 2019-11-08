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
cat << EOF | try 2
3
3
1
2
EOF

## test case 2
cat << EOF | try -1
4
3
4
1
2
EOF

## test case 2
cat << EOF | try 3
5
3
3
4
2
4
EOF
