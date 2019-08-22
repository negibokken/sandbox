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
cat << EOF | try 1 3 3 3 4 5 6
4 4
##.#
....
##.#
.#.#
EOF

## test case 2
cat << EOF | try 2 3 3 4
3 3
#..
.#.
..#
EOF

## test case 2
cat << EOF | try 2 3 3 4
4 5
.....
.....
..#..
.....
EOF

## test case 2
cat << EOF | try 2 3 3 4
7 6
......
....#.
.#....
..#...
..#...
......
.#..#.
EOF

## test case 2
cat << EOF | try 2 3 3 4
7 6
######
######
######
######
######
######
######
EOF

## test case 2
cat << EOF | try 2 3 3 4
7 6
......
......
......
......
......
......
.....#
EOF

## test case 2
cat << EOF | try 2 3 3 4
1 1
.
EOF

## test case 2
cat << EOF | try 2 3 3 4
1 1
#
EOF

## test case 2
cat << EOF | try 2 3 3 4
2 2
# .
. #
EOF

