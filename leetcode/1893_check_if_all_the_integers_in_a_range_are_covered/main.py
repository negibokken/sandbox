#!/usr/bin/python3

from typing import List
import json


class Solution:

    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        segments = [False] * 51
        for r in ranges:
            for i in range(r[0], r[1]+1):
                segments[i] = True
        for i in range(left, right+1):
            if not segments[i]:
                return False
        return True


ranges = json.loads(input())
left = int(input())
right = int(input())

sol = Solution()
print(sol.isCovered(ranges, left, right))
