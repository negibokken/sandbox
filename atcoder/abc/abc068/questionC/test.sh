#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

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
cat << EOF | try POSSIBLE
3 2
1 2
2 3
EOF

## test case 2
cat << EOF | try IMPOSSIBLE
4 3
1 2
2 3
3 4
EOF

## test case 2
cat << EOF | try IMPOSSIBLE
100000 1
1 99999
EOF

## test case 2
cat << EOF | try POSSIBLE
5 5
1 3
4 5
2 3
2 4
1 4
EOF
