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
                cnt = 0
                q = deque()
                q.append((y, x))
                while q:
                    _y, _x = q.pop()
                    if _y < 0 or _x < 0 or _y >= m or _x >= n:
                        continue
                    if visited[_y][_x]:
                        continue
                    visited[_y][_x] = True
                    if grid[_y][_x] == 0:
                        continue
                    if grid[_y][_x] == 1:
                        cnt += 1
                        q.append((_y-1, _x))
                        q.append((_y+1, _x))
                        q.append((_y, _x+1))
                        q.append((_y, _x-1))
                ans = max(ans, cnt)
        return ans


grid = json.loads(input())

sol = Solution()
print(sol.maxAreaOfIsland(grid))
