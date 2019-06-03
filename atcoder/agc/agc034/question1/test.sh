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
cat << EOF | try Yes
7 1 3 6 7
.#..#..
EOF

## test case 2
cat << EOF | try No
7 1 3 7 6
.#..#..
EOF

## test case 3
cat << EOF | try No
7 1 3 7 8
.#..##..
EOF

## test case 4
cat << EOF | try Yes
15 1 3 15 13
...#.#...#.#...
EOF

## test case 4
cat << EOF | try No
15 1 3 13 12
...#.#..#.#..
EOF

## test case 4
cat << EOF | try No
13 1 3 13 12
...#.#..#.#..
EOF

## test case 4
cat << EOF | try No
14 1 3 14 13
...##.#..#.#..
EOF

## test case 4
cat << EOF | try No
14 1 3 14 12
...#.#..#.#...
EOF

## test case 4
cat << EOF | try Yes
14 1 2 10 11
..#.#.#.#..
EOF

## test case 4
cat << EOF | try No
14 1 2 11 10
..#.#.#.#..
EOF

## test case 4
cat << EOF | try No
14 1 3 12 11
...#.#.#.#..
EOF

## test case 4
cat << EOF | try Yes
14 1 3 14 13
...#.#...#.#..
EOF

## test case 4
cat << EOF | try Yes
14 1 3 14 13
..............
EOF

## test case 4
cat << EOF | try No
14 1 3 13 14
...#########..
EOF

## test case 4
cat << EOF | try Yes
16 1 3 14 13
...#.#...#.#..#.
EOF

## test case 4
cat << EOF | try Yes
16 1 3 16 14
...#.#..#.#...#.
EOF

## test case 4
cat << EOF | try Yes
17 1 3 16 17
...#.#..#.#..#...
EOF

## test case 4
cat << EOF | try Yes
17 1 3 16 17
...#.#..#.#..#...
EOF

## test case 4
cat << EOF | try Yes
16 1 2 16 15
...#.#..#.#..#..
EOF

## test case 4
cat << EOF | try Yes
16 12 13 15 16
...#.#..#.#..#..
EOF

## test case 4
cat << EOF | try No
16 12 13 16 15
...#.#..#.#..#..
EOF
