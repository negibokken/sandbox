#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
  actual=`echo $actual | sed 's/\n/ /g'`
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
cat << EOF | try "[[1,2,null,4],[6],[7]]"
7
1 2 3 4 5 6 7
2
3 5
EOF

## test case 2
cat << EOF | try "[[1,2,4]]"
5
1 2 4 null 3
1
3
EOF

cat << EOF | try "[[1,null,2],[4]]"
7
1 null 2 null 3 null 4
1
3
EOF

cat << EOF | try "[[1],[4]]"
5
1 2 null 4 3
2
2 3
EOF

cat << EOF | try "[[1],[4]]"
7
1 2 3 null null null 4
2
2 1
EOF
