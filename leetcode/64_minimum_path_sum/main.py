#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                t = grid[i][j]
                a = 1000
                b = 1000
                if i-1 >= 0:
                    a = t + grid[i-1][j]
                if j-1 >= 0:
                    b = t + grid[i][j-1]
                if a == 1000 and b == 1000:
                    continue
                grid[i][j] = min(a, b)
        return grid[n-1][m-1]


arr = json.loads(input())

sol = Solution()
print(sol.minPathSum(arr))
