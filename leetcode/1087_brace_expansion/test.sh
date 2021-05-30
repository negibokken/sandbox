#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

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
cat << EOF | try "[acdf,acde,bcdf,bcef]"
{a,b}c{d,e}f
EOF

## test case 2
cat << EOF | try "abcd"
abcd
EOF


cat << EOF | try "[ax,ay,az,bx,by,bz]"
{a,b}{z,x,y}
EOF
