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

try "aabcccccaaa" "a2b1c5a3"
try "abc" "abc"
try "abcccccccc" "a1b1c8"

