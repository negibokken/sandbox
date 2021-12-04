#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | python3 ./main.py`

  actual=`echo "$actual"`
  # actual=`echo $actual | sed 's/\n/ /g'`
  expected=`echo "$expected"`

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
cat << EOF | try "[[3],[20,9],[15,7]]"
[3,9,20,null,null,15,7]
EOF

## test case 2
cat << EOF | try "[[1]]"
[1]
EOF

## test case 2
cat << EOF | try "[]"
[]
EOF

cat << EOF | try "[[1],[3,2],[4,5]]"
[1,2,3,4,null,null,5]
EOF

cat << EOF | try "[[69],[68,73],[18,20,18,39],[70,93,5,42,-1,13,-3,7],[63,17,91,-4,30,-1,64,-4,16,49,48,78,51,43],[5,35,57,61,14,28,54,82,25,71,67,89,81,41,78,58,-6,80,36,9,53,45,92],[83,9,18,-9,-9,50,92,93,0,80,62,1,28,29,27,89,21,85,-9,56,56,-9,43,29,97,-7,35,25,90,67,53,18,61,7,23,81,37,19],[97,78,87,89,2,50,37,12,37,11,71,59,43,64,7,78,85,13,48,99,46,38,47,64,27,72,59,21,-7,-8,97,50,18,14,52,7,22,-2,33,53,55,68,83,87,11,37,1,28,39,49,-2,37,77,19,0,2,26],[31,86,37,96,34,38,6,36,99,63,12,82,81,70,19,81,32,79,10,91,48,-3,94,65,20,26,96,21,92,91,89,9,74,96,64,67,50,96,40,78,27,3,17,2,45,13,17,45,69,30,43,4,13,-6,66,6,16,48,55,98,69,57,5,9,65,-9,55,2,68],[55,23,45,85,12,57,62,63,31,22,65,-4,-8,3,5,87,83,16,95,89,53,92,71,18,48,62,93,97,-4,2,83,43,92,18,13,57,41,34,45,36,23,6,3,21,38,11,29,95,18,65,6,76,24,48,71,60,83,-9,29,62,47,42,86,42,80,1,30,38,-7,20,35,43,32,51,61,5],[81,83,23,3,83,-4,64,15,50,57,4,29,87,22,92,67,90,93,47,46,28,72,18,59,25,3,74,-5,28,-1,61,15,79,16,59,47,-7,98,31,50,19,93,22,-5,40,7..."
[69,73,68,18,20,18,39,7,-3,13,-1,42,5,93,70,63,17,null,91,-4,30,null,-1,64,-4,16,49,48,78,51,43,92,45,null,53,9,36,80,-6,58,78,null,null,41,81,89,67,71,null,25,null,82,54,28,14,61,57,35,5,83,9,18,null,-9,-9,50,92,93,null,0,80,62,1,28,29,27,89,21,null,85,-9,null,56,56,-9,null,null,43,null,29,97,-7,null,35,25,90,67,53,18,61,7,23,81,37,19,26,2,0,19,null,null,77,37,-2,null,49,39,28,1,37,11,87,83,68,55,53,33,-2,22,7,52,null,14,null,18,50,97,-8,-7,null,21,59,72,27,null,64,null,null,47,null,null,38,46,null,null,99,null,null,48,13,85,78,7,64,43,59,71,11,37,12,37,50,2,null,null,89,87,null,78,97,null,31,86,37,96,34,38,6,36,null,null,99,63,null,12,null,82,null,81,70,19,null,81,32,null,null,null,null,79,10,null,91,48,-3,94,65,null,20,26,96,21,92,91,null,89,9,74,null,null,96,null,64,67,50,96,null,null,null,null,null,null,40,78,null,27,3,17,null,null,2,45,null,null,null,null,null,13,null,null,17,45,69,30,null,null,43,null,4,13,-6,66,6,null,16,48,55,98,69,57,null,5,9,65,-9,55,2,null,null,null,null,null,null,68,null,null,null,5,61,51,null,null,32,43,null,35,20,null,-7,38,30,1,80,null,null,42,86,42,null,null,null,null,47,null,null,null,62,29,-9,83,60,71,48,null,24,null,76,6,65,18,95,29,11,null,38,null,null,null,null,21,3,6,23,36,null,45,null,34,null,null,null,null,null,null,41,null,57,13,18,92,43,83,null,null,null,null,null,null,null,2,-4,97,null,93,null,62,null,null,48,18,71,92,53,89,null,null,null,95,null,16,null,null,null,83,87,5,null,null,3,-8,-4,65,null,null,null,22,null,31,null,null,null,63,null,null,62,null,57,12,85,45,23,55,null,null,null,81,83,23,null,3,null,83,null,-4,null,null,null,null,null,64,null,15,50,57,null,null,null,4,null,null,null,29,null,null,87,null,22,92,null,null,67,90,null,93,47,46,null,null,null,28,72,18,59,25,3,74,null,null,null,-5,28,-1,61,15,null,null,null,null,79,null,16,null,null,59,47,-7,98,31,50,null,null,null,null,19,null,93,null,22,null,null,-5,40,null,null,null,75,30,null,7,53,76,null,null,null,null,null,68,19,null,63,41,91,null,43,null,49,null,null,null,null,null,46,null,null,87,74,49,1,21,62,6,34,77,null,null,null,null,null,null,-9,61,null,null,null,7,null,45,null,null,63,null,null,7,null,null,16,86,null,null,63,null,61,72,null,13,null,24,91,null,null,59,null,null,48,14,77,null,null,null,null,92,null,null,null,null,null,null,84,null,null,76,82,63,84,84,94,null,null,null,null,null,47,40,null,null,null,null,75,20,null,null,null,-9,null,null,24,74,null,51,null,null,91,null,83,17,null,null,null,42,49,88,57,85,1,null,94,null,28,36,78,null,53,null,27,25,46,97,58,null,null,null,null,null,null,null,null,12,33,null,null,6,null,null,null,87,null,null,null,null,null,null,null,9,null,83,null,null,null,90,11,null,61,null,89,null,46,null,86,81,null,null,null,null,null,null,null,53,null,null,59,null,null,null,null,null,null,null,29,null,47,97,0,null,null,null,null,9,null,17,null,91,45,9,61,21,null,null,64,null,69,null,44,null,null,null,null,12,null,2,-8,88,null,null,null,null,null,-8,null,93,null,null,null,86,null,null,97,null,null,null,null,72,null,null,null,null,null,50,null,null,null,null,null,47,70,null,62,null,-3,-5,59,15,null,-3,37,null,null,null,null,20,-2,null,8,90,null,null,null,61,null,null,null,null,null,null,null,15,12,95,null,null,73,11,76,76,49,null,null,51,null,null,null,null,null,null,null,null,null,null,null,null,null,42,null,null,-9,null,null,null,null,null,null,null,null,80,null,null,70,31,78,98,null,null,null,null,null,null,null,null,null,null,null,null,7,null,null,null,null,57,null,null,null,null,-3,null,null,-7,null,31,42,null,null,null,null,62,17,7,null,null,63,null,null,null,null,83,51,null,76,77,null,null,40,null,null,95,null,27,55,61,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,95,null,93,19,null,37,null,73,null,null,null,null,null,75,null,null,null,null,null,22,null,null,null,null,null,-7,99,null,null,null,null,null,94,63,null,null,null,null,null,null,null,39,77,null,-2,15,null,69,33,9,null,null,null,null,null,null,null,null,null,42,null,null,null,69,35,null,36,null,11,null,null,null,52,null,null,null,null,null,null,null,51,50,null,null,null,null,null,null,30,null,null,null,null,null,63,null,null,null,null,null,null,56,28]
EOF
