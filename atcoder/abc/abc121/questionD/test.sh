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
cat << EOF | try 5
2 4
EOF

## test case 2
cat << EOF | try 435
123 456
EOF

## test case 2
cat << EOF | try 123456789012
123456789012 123456789012
EOF

## e e e
cat << EOF | try 6
2 6
EOF

## e e o
cat << EOF | try 7
2 8
EOF

# e o o
cat << EOF | try 1
2 7
EOF

# e o e
cat << EOF | try 0
2 9
EOF

# o e e
cat << EOF | try 11
3 8
EOF

# o e e
cat << EOF | try 10
3 10
EOF

# o o e
cat << EOF | try 3
3 7
EOF

# o o e
cat << EOF | try 2
3 9
EOF
