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
cat << EOF | try Heisei
2019/04/30
EOF

## test case 2
cat << EOF | try TBD
2019/11/01
EOF

## test case 2
cat << EOF | try Heisei
2019/04/30
EOF

## test case 2
cat << EOF | try TBD
2019/05/01
EOF
