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
cat << EOF | try 2
3
ABCA
XBAZ
BAD
EOF

## test case 2
cat << EOF | try 4
9
BEWPVCRWH
ZZNQYIJX
BAVREA
PA
HJMYITEOX
BCJHMRMNK
BP
QVFABZ
PRGKSPUNA
EOF

cat << EOF | try 4
7
RABYBBE
JOZ
BMHQUVA
BPA
ISU
MCMABAOBHZ
SZMEHMA
EOF
