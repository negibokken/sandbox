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
3
apple
orange
apple
1
grape
EOF

## test case 2
cat << EOF | try 1
3
apple
orange
apple
5
apple
apple
apple
apple
apple
EOF

## test case 2
cat << EOF | try 0
1
voldemort
10
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
voldemort
EOF

## test case 2
cat << EOF | try 1
6
red
red
blue
yellow
yellow
red
5
red
red
yellow
green
blue
EOF
