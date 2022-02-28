#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid)
        if n == 0:
            return 0
        m = len(obstacleGrid[0])
        if m == 0:
            return 0
        dp = [[0] * m for _ in range(n)]
        dp[0][0] = 1 if obstacleGrid[0][0] == 0 else 0
        for i in range(n):
            for j in range(m):
                if i - 1 >= 0:
                    dp[i][j] += dp[i-1][j] if obstacleGrid[i][j] == 0 else 0
                if j-1 >= 0:
                    dp[i][j] += dp[i][j-1] if obstacleGrid[i][j] == 0 else 0
        return dp[n-1][m-1]


arr = json.loads(input())

sol = Solution()
print(sol.uniquePathsWithObstacles(arr))
