#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | LOCAL_TEST=yes ./main`

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
cat << EOF | try "11211 1#2#1 11211"
3 5
.....
.#.#.
.....
EOF

## test case 2
cat << EOF | try "##### ##### #####"
3 5
#####
#####
#####
EOF

## test case 2
cat << EOF | try "#####3 #8#7## ####5# 4#65#2 #5##21 #4#310"
6 6
#####.
#.#.##
####.#
.#..#.
#.##..
#.#...
EOF

## test case 2
cat << EOF | try "3# ##"
2 2
.#
##
EOF

## test case 2
cat << EOF | try "#3 ##"
2 2
#.
##
EOF

## test case 2
cat << EOF | try "## 3#"
2 2
##
.#
EOF

## test case 2
cat << EOF | try "## #3"
2 2
##
#.
EOF


## test case 2
cat << EOF | try "## #3"
3 4
####
#.##
####
EOF

## test case 2
cat << EOF | try "## #3"
4 3
###
###
###
###
EOF

## test case 2
cat << EOF | try "## #3"
2 2
#.
..
EOF


