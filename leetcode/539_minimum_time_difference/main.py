#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def convert(time):
            return int(time[:2]) * 60 + int(time[3:])
        minutes = list(map(convert, timePoints))
        minutes.sort()

        return min((y-x) % (24*60) for x, y in zip(minutes, minutes[1:] + minutes[:1]))


arr = json.loads(input())

sol = Solution()
print(sol.findMinDifference(arr))
