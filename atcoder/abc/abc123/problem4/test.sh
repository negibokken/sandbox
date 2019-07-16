#!/bin/bash
for i in {1..3}; do
  expected=`cat tests/ans$i.txt`
  input=`cat tests/test$i.txt`
  actual=`cat tests/test$i.txt | ./main`
  if [ "$actual" = "$expected" ]; then
    echo "$input => `echo $actual | tr '\n' ' '`"
  else
    echo "[Error] ======"
    echo "$input =>"
    echo "Actual"
    echo "`echo $actual | tr '\n' ' '`"
    echo "Expected"
    echo `echo $expected | tr '\n' ' '`
    #exit 1
  fi
done
