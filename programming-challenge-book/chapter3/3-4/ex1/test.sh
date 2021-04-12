#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try 22
5 8
0 3 4
0 1 3
1 2 5
2 3 5
2 0 4
3 4 3
4 0 7
4 1 6
EOF


## test case 1
cat << EOF | try 16
4 6
0 1 2
1 2 3
1 3 9
2 0 1
2 3 6
3 2 4
EOF

## test case 1
cat << EOF | try -1
3 3
0 1 1
1 2 1
0 2 1
EOF

