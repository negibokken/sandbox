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
cat << EOF | try 2.2761423749
3
0 0
1 0
0 1
EOF

## test case 2
cat << EOF | try 91.9238815543
2
-879 981
-866 890
EOF
exit
## test case 2
cat << EOF | try 7641.9817824387
8
-406 10
512 859
494 362
-955 -475
128 553
-986 -885
763 77
449 310
EOF
