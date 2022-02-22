#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        for i in range(n):
            for j in range(m):
                t = grid[i][j]
                if i-1 >= 0 and j-1 >= 0:
                    grid[i][j] = min(t + grid[i-1][j], t+grid[i][j-1])
                elif i-1 >= 0:
                    grid[i][j] = t + grid[i-1][j]
                elif j-1 >= 0:
                    grid[i][j] = t + grid[i][j-1]
        return grid[n-1][m-1]


arr = json.loads(input())

sol = Solution()
print(sol.minPathSum(arr))
