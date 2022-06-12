#!/bin/bash

try() {
  file=$1
  expected="${@:2:($#-1)}"

  actual=`./$file`

  actual=`echo "$actual"`
  actual=`echo $actual | sed 's/\n/ /g'`
  expected=`echo "$expected"`

  if [ "$actual" = "$expected" ]; then
    echo "OK"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

echo $file "==="

try main.sh "the 4 is 3 sunny 2 day 1"
