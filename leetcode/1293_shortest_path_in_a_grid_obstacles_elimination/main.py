#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


dir = [
    [0, -1],  # up
    [1, 0],  # right
    [0, 1],  # down
    [-1, 0],  # left
]


class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        inf = sys.maxsize
        dp = [[[inf] * len(grid[0]) for i in range(len(grid))]
              for _ in range(k+1)]
        dp[k][0][0] = 0
        curx, cury = 0, 0
        m, n = len(grid[0]), len(grid)

        def bfs(curx, cury):
            for i in range(4):
                x, y = dir[i]
                nextx, nexty = curx + x, cury + y
                if not (0 <= nextx < m) or not (0 <= nexty < n):
                    continue
                offset = 0

                if grid[nexty][nextx] == 1:
                    offset = 1
                updated = False
                for i in range(k, -1, -1):
                    if i - offset < 0:
                        continue
                    cur = dp[i-offset][nexty][nextx]
                    dp[i-offset][nexty][nextx] = min(dp[i-1]
                                                     [nexty][nextx], dp[i][cury][curx] + 1)
                    if cur != dp[i-offset][nexty][nextx]:
                        updated = True
                if updated:
                    bfs(nextx, nexty)
        bfs(curx, cury)
        ans = inf
        for i in range(k+1):
            ans = min(ans, dp[i][n-1][m-1])
        ans = -1 if ans == inf else ans
        return ans


arr = json.loads(input())
k = int(input())

sol = Solution()
print(sol.shortestPath(arr, k))
