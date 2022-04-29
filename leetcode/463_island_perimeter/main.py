#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint

#  x
# x0x
#  x
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        total = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if not grid[i][j]:
                    continue
                cnt = 0
                for k in range(4):
                    ni, nj = i + dy[k], j + dx[k]
                    if ni < 0 or ni >= len(grid):
                        cnt += 1
                        continue
                    if nj < 0 or nj >= len(grid[0]):
                        cnt += 1
                        continue
                    if not grid[ni][nj]:
                        cnt += 1
                total += cnt

        return total


arr = json.loads(input())

sol = Solution()
print(sol.islandPerimeter(arr))
