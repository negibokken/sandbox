#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

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
cat << EOF | try UURDDLLUUURRDRDDDLLU
0 0 1 2
EOF

## test case 2
cat << EOF | try UURRURRDDDLLDLLULUUURRURRDDDLLDL
-2 -2 1 1
EOF
