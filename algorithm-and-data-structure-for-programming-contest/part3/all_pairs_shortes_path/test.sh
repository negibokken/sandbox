#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo $actual`
  expected=`echo $expected`

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
cat << EOF | try "0 1 3 4 INF 0 2 3 INF INF 0 1 INF INF 7 0"
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7
EOF

## test case 2
cat << EOF | try "0 1 -5 -4 INF 0 2 3 INF INF 0 1 INF INF 7 0"
4 6
0 1 1
0 2 -5
1 2 2
1 3 4
2 3 1
3 2 7
EOF

## test case 2
cat << EOF | try "NEGATIVE CYCLE"
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 -7
EOF
