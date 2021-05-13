#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  #actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try true
11
1 2 3 4 5 6 null null null 7 8
13
1 3 2 null 6 4 5 null null null null 8 7
EOF

## test case 2
cat << EOF | try true
0
0
EOF

## test case 2
cat << EOF | try false
0
1
1
EOF

## test case 2
cat << EOF | try false
3
0 null 1
0
EOF

## test case 2
cat << EOF | try true
3
0 null 1
2
0 1
EOF
