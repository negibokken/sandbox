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
84 97 66
79 89 11
61 59 7
7
89
7
87
79
24
84
30
EOF

## test case 2
cat << EOF | try No
41 7 46
26 89 2
78 92 8
5
6
45
16
57
17
EOF

## test case 2
cat << EOF | try Yes
60 88 34
92 41 43
65 73 48
10
60
43
88
11
48
73
65
41
92
34
EOF
