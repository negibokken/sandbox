#!/bin/bash

try() {
  expected="$1"
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
cat << EOF | try 1
3
#.#
EOF

## test case 2
cat << EOF | try 2
5
#.##.
EOF

## test case 3
cat << EOF | try 0
9
.........
EOF

## test case 4
cat << EOF | try 0
9
#########
EOF

## test case 5
cat << EOF | try 5
14
#.##.#...#....
EOF

## test case 6
cat << EOF | try 2
4
##..
EOF

## test case 7
cat << EOF | try 0
4
..##
EOF

## test case 8
cat << EOF | try 0
1
.
EOF

## test case 8
cat << EOF | try 0
1
#
EOF

## test case 8
cat << EOF | try 1
3
.#.
EOF

## test case 8
cat << EOF | try 1
4
.#..
EOF

## test case 1
cat << EOF | try 1
4
###.
EOF

## test case 1
cat << EOF | try 1
5
.###.
EOF

## test case 1
cat << EOF | try 1
5
.###.
EOF

## test case 1
cat << EOF | try 1
6
.###.#
EOF

## test case 5
cat << EOF | try 5
15
#.##.#...#....#
EOF

## test case 5
cat << EOF | try 1
4
#.##
EOF

## test case 5
cat << EOF | try 1
6
.#..##
EOF

## test case 5
cat << EOF | try 3
8
..#..##.
EOF

## test case 5
cat << EOF | try 1
8
..#..###
EOF

## test case 5
cat << EOF | try 4
8
##.##...
EOF

## test case 5
cat << EOF | try 4
8
##.##...
EOF
