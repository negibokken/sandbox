#/usr/bin/python3
import sys
from typing import List

class Solution:
    def rec(self,grid: List[List[str]], i, j):
        if i < 0 or len(grid) <= i or j < 0 or len(grid[i]) <= j:
            return
        if grid[i][j] == '0':
            return
        grid[i][j] = '0'
        for c in [[0,-1],[-1,0],[1,0],[0,1]]:
            self.rec(grid,i+c[0],j+c[1])

    def numIslands(self, grid: List[List[str]]) -> int:
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1':
                    ans += 1
                    self.rec(grid,i,j)
        return ans

a = []
for l in sys.stdin:
    s = l.strip().split(",")
    a.append(s)

s = Solution()
print(s.numIslands(a))
