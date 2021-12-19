#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    segments = []

    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        cur = None
        for r in ranges:
            if not cur:
                cur = r
                continue
            if cur[1] >= r[0]:
                if cur[0] >= r[0]:
                    cur[0]
        return True


ranges = json.loads(input())
left = int(input())
right = int(input())

sol = Solution()
print(sol.isCovered(ranges, left, right))
