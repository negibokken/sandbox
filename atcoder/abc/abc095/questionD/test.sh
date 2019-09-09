#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "OK"
    # echo "$input => $actual"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}


cat << EOF | try 73
6 100000000000000
1 10
2 20
3 30
1940 500
99999999999998 10
99999999999999 10
EOF

cat << EOF | try 514
6 2000
1 10
2 20
3 30
1940 500
1955 10
1950 10
EOF

cat << EOF | try 514
6 2000
50 10
55 10
60 500
1997 30
1998 20
1999 10
EOF
#exit

cat << EOF | try 145
5 6
1 10
2 20
3 30
4 40
5 50
EOF

cat << EOF | try 145
5 6
1 50
2 40
3 30
4 20
5 10
EOF

cat << EOF | try 132
5 2000
1 10
2 20
3 30
4 40
1990 50
EOF

## test case 1
cat << EOF | try 191
3 20
4 1
11 120
18 80
EOF

## test case 1
cat << EOF | try 191
3 20
2 80
9 120
16 1
EOF


## test case 2
cat << EOF | try 192
3 20
2 80
9 1
16 120
EOF

## test case 2
cat << EOF | try 0
1 100000000000000
50000000000000 1
EOF

## test case 2
cat << EOF | try 6500000000
15 10000000000
400000000 1000000000
800000000 1000000000
1900000000 1000000000
2400000000 1000000000
2900000000 1000000000
3300000000 1000000000
3700000000 1000000000
3800000000 1000000000
4000000000 1000000000
4100000000 1000000000
5200000000 1000000000
6600000000 1000000000
8000000000 1000000000
9300000000 1000000000
9700000000 1000000000
EOF

cat << EOF | try 2
4 100
2 1
3 2
4 3
98 1
EOF

cat << EOF | try 0
4 100
7 1
8 2
9 3
98 1
EOF

cat << EOF | try 0
4 100
2 1
91 3
92 2
93 1
EOF
