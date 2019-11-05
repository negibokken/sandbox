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
cat << EOF | try i18n
internationalization
EOF

## test case 2
cat << EOF | try s4s
smiles
EOF

## test case 2
cat << EOF | try x1z
xyz
EOF

## test case 2
cat << EOF | try k8s
kubernetes
EOF
