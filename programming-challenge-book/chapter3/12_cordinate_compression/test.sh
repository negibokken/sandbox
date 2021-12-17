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

# 0001000010
# 0001000010
# 0001000010
# 1111110010
# 0001000010
# 0001000001
# 0001000001
# 1111111111
# 0001000001
# 0001000001
## test case 1
# cat << EOF | try 6
# 10 10 5
# 1 1 4 9 10
# 6 10 4 9 10
# 4 8 1 1 6
# 4 8 10 5 10
# EOF

cat << EOF | try 2
7 7 1
4
4
1
7
EOF
