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
cat << EOF | try
6
khabarovsk 20
moscow 10
kazan 50
kazan 35
moscow 60
khabarovsk 40
EOF

## test case 2
cat << EOF | try  2 3 3 4
10
yakutsk 10
yakutsk 20
yakutsk 30
yakutsk 40
yakutsk 50
yakutsk 60
yakutsk 70
yakutsk 80
yakutsk 90
yakutsk 100
EOF
