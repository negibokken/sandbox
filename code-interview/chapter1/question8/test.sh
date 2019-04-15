#!/bin/bash

try() {
  input="$1"
  expected="$2"

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$expected expected, but got $actual"
    exit 1
  fi
}

try "0,2,3\n4,5,6\n7,8,9" "0,0,0\n0,5,6\n0,8,9"
try "0,3\n4,5" "0,0\n0,5"

