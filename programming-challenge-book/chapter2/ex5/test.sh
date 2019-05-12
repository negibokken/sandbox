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
## 1-yen 10-yen 50-yen 100-yen 500-yen
## want yen
cat << EOF | try 6
3 2 1 3 0 2
620
EOF

cat << EOF | try 0
3 2 1 3 0 2
0
EOF

cat << EOF | try 15
4 1 4 1 4 1
999
EOF
