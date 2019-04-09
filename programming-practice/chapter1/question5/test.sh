#!/bin/bash

try() {
  input="$1"
  expected="$2"

  echo $input | ./main
  actual=$?

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$expected expected, but got $actual"
    exit 1
  fi
}

try "pale ple" 1
try "pales pale" 1
try "pale bale" 1
try "pale bake" 0
try "fish bake" 0
try "pokemon bake" 0

