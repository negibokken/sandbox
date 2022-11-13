#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
from collections import deque


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[False for i in range(n)] for j in range(m)]
        ans = 0
        for y in range(m):
            for x in range(n):
                if visited[y][x] or grid[y][x] == 0:
                    continue
                cnt = 0
                q = deque()
                q.append((y, x))
                while q:
                    y, x = q.pop()
                    if y < 0 or x < 0 or y >= m or x >= n:
                        continue
                    if visited[y][x] or grid[y][x] == 0:
                        continue
                    visited[y][x] = True
                    if grid[y][x] == 1:
                        cnt += 1
                        q.append((y-1, x))
                        q.append((y+1, x))
                        q.append((y, x+1))
                        q.append((y, x-1))
                ans = max(ans, cnt)
        return ans


grid = json.loads(input())

sol = Solution()
print(sol.maxAreaOfIsland(grid))
