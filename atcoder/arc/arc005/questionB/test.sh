#!/bin/bash

try() {
  expected="$@"
  input=`cat -`

  actual=`echo "$input" | ./main`

  actual=`echo "$actual"`
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
cat << EOF | try 8226
3 5 R
790319030
091076399
143245946
590051196
398226115
442567154
112705290
716433235
221041645
EOF

## test case 2
cat << EOF | try 2853
8 9 LU
206932999
471100777
973172688
108989704
246954192
399039569
944715218
003664867
219006823
EOF

## test case 2
cat << EOF | try 4646
5 7 D
271573743
915078603
102553534
996473623
595593497
573572507
340348994
253066837
643845096
EOF

## test case 2
cat << EOF | try 0700
2 2 LU
729142134
509607882
640003027
215270061
214055727
745319402
777708131
018697986
277156993
EOF

## test case 2
cat << EOF | try 8878
8 7 RD
985877833
469488482
218647263
856777094
012249580
845463670
919136580
011130808
874387671
EOF

