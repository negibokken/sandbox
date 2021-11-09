#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

  actual=`echo "$actual"`
  # actual=`echo $actual | sed 's/\n/ /g'`
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

# ## test case 1
# cat << EOF | try 1
# ["hello","world"]
# 2
# 8
# EOF
# 
# ## test case 2
# cat << EOF | try 2
# ["a", "bcd", "e"]
# 3
# 6
# EOF
# 
# ## test case 2
# cat << EOF | try 1
# ["i","had","apple","pie"]
# 4
# 5
# EOF

## test case 2
cat << EOF | try 6
["i"]
3
3
EOF

## test case 2
cat << EOF | try 0
["aaaa"]
3
3
EOF

cat << EOF | try 50000000
["a"]
10000
10000
EOF
