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
3 3
...
.#.
...
EOF

## test case 2
cat << EOF | try  3
6 6
..#..#
......
#..#..
......
.#....
....#.
EOF

cat << EOF | try 2
2 3
...
.#.
EOF

cat << EOF | try 2
3 2
..
#.
..
EOF
