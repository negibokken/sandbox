#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        r1, r1_invert = grid[0], [1-val for val in grid[0]]
        for i in range(1, len(grid)):
            if grid[i] != r1 and grid[i] != r1_invert:
                return False
        return True


arr = json.loads(input())

sol = Solution()
print(sol.removeOnes(arr))
