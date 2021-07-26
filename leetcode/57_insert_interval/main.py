#/usr/bin/python3

import bisect
from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        s, e = newInterval[0], newInterval[1]
        left = [i for i in intervals if i[1] < s]
        right = [i for i in intervals if i[0] > e]
        if left + right != intervals:
            s = min(s, intervals[len(left)][0])
            e = max(e, intervals[~len(right)][1])
        return left + [[s,e]] + right
        

sol = Solution()
n=int(input())
intervals = []
for i in range(n):
    ele = list(map(int, input().split(" ")))
    intervals.append(ele)
newinterval = list(map(int, input().split(" ")))

print(sol.insert(intervals, newinterval))
