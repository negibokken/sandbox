#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        balls = [-1 for i in range(n)]
        for i in range(len(balls)):
            curx, cury = i, 0
            while cury < m:
                if grid[cury][curx] == 1:
                    if not(curx + 1 < n and grid[cury][curx+1] == 1):
                        break
                    curx += 1
                elif grid[cury][curx] == -1:
                    if not(curx - 1 >= 0 and grid[cury][curx-1] == -1):
                        break
                    curx -= 1
                cury += 1
            balls[i] = curx if cury == m else -1
        return balls


def printGrid(grid):
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                print("\\ ", end="")
            else:
                print("/ ", end="")
        print("")


grid = json.loads(input())

sol = Solution()
aprint(sol.findBall(grid))
