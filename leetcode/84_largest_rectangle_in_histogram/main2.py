#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        max_area = 0
        for i in range(len(heights)):
            for j in range(i, len(heights)):
                min_height = sys.maxsize
                for k in range(i, j+1):
                    min_height = min(min_height, heights[k])
                max_area = max(max_area, min_height*(j-i+1))
        return max_area


arr = json.loads(input())

sol = Solution()
print(sol.largestRectangleArea(arr))
