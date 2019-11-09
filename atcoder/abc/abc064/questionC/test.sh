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
cat << EOF | try "2 2"
4
2100 2500 2700 2700
EOF

## test case 2
cat << EOF | try "3 5"
5
1100 1900 2800 3200 3200
EOF

## test case 2
cat << EOF | try "1 1"
20
800 810 820 830 840 850 860 870 880 890 900 910 920 930 940 950 960 970 980 990
EOF

## test case 2
cat << EOF | try "1 2"
2
3300 3300
EOF

