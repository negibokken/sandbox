#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo $input | ./main`

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "==="
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

## test case 1
cat << EOF | try 3
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W.....WW.
..W.......W.
EOF

