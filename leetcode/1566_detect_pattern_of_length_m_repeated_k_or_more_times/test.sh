#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

  actual=`echo "$actual"`
  #actual=`echo $actual | sed 's/\n/ /g'`
  expected=`echo "$expected"`

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
cat << EOF | try true
6
1 2 4 4 4 4
1 3
EOF

## test case 2
cat << EOF | try true
8
1 2 1 2 1 1 1 3
2 2
EOF

## test case 2
cat << EOF | try false
6
1 2 1 2 1 3
2 3
EOF

## test case 2
cat << EOF | try false
5
1 2 3 1 2
2 2
EOF

## test case 2
cat << EOF | try false
4
2 2 2 2
2 3
EOF

cat << EOF | try true
2
2 2
1 2
EOF

cat << EOF | try false
10
2 2 1 2 2 1 1 1 2 1
2 2
EOF

cat << EOF | try true
9
1 2 2 2 1 1 2 2 2
1 3
EOF
