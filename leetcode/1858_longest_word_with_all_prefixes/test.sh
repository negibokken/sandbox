#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

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
cat << EOF | try kiran
["k","ki","kir","kira", "kiran"]
EOF

## test case 2
cat << EOF | try apple
["a", "banana", "app", "appl", "ap", "apply", "apple"]
EOF

## test case 2
cat << EOF | try ""
["abc", "bc", "ab", "qwe"]
EOF
