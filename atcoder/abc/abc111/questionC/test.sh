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
cat << EOF | try 1
4
3 1 3 2
EOF

## test case 2
cat << EOF | try 0
6
105 119 105 119 105 119
EOF

## test case 2
cat << EOF | try 2
4
1 1 1 1
EOF

## test case 2
cat << EOF | try 1
2
105 105
EOF

## test case 2
cat << EOF | try 0
2
101 105
EOF

## test case 2
cat << EOF | try 3
6
105 105 105 105 105 105
EOF

## test case 2
cat << EOF | try 4
8
105 105 105 105 106 107 106 103
EOF

## test case 2
cat << EOF | try 4
8
105 105 105 105 107 106 103 106
EOF

## test case 2
cat << EOF | try 1
2
101 101
EOF

## test case 2
cat << EOF | try 4
8
106 105 106 105 107 106 103 106
EOF
