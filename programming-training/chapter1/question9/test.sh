#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  # actual=`echo $actual`
  # expected=`echo $expected`

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
cat << EOF | try Yes
waterbottle
erbottlewat
EOF


## test case 1
cat << EOF | try Yes
abcdefghij
hijabcdefg
EOF

## test case 1
cat << EOF | try No
abcdefghij
hijabcdefgh
EOF

