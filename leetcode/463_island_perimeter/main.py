#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        i, j = 0, 0
        while i < len(grid):
            while j < len(grid[i]):
                j += 1
            i += 1


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
