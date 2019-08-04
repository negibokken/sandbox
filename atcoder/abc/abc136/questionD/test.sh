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
cat << EOF | try "0 1 2 1 1"
RRLRL
EOF

### test case 2
cat << EOF | try "0 3 3 0 0 0 1 1 0 2 2 0"
RRLLLLRLRRLL
EOF

# test case 3
cat << EOF | try "0 0 3 2 0 2 1 0 0 0 4 4 0 0 0 0"
RRRLLRLLRRRLLLLL
EOF
