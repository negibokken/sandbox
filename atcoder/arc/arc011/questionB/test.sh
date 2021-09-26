#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

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

## test case 1
cat << EOF | try 7003 756 791
3
Mozart plays magic.
EOF

## test case 2
cat << EOF | try 15716 492 6
3
Columbus found USA.
EOF

## test case 2
cat << EOF | try 85 616606 40 0983 892
7
I have a scissors for right hand.
EOF

## test case 2
cat << EOF | try 11 1
4
abc ab aa aiueo
EOF

## test case 2
cat << EOF | try ""
4
aaa aa a aa
EOF
