#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class Solution:
    def __init__(self):
        self.arr = []

    def dfs(self, root: Optional[TreeNode]):
        if not root:
            return
        self.dfs(root.left)
        self.arr.append(root.val)
        self.dfs(root.right)

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        mi = sys.maxsize
        for i in range(1, len(self.arr)):
            mi = min(mi, self.arr[i]-self.arr[i-1])

        return mi


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.minDiffInBST(root))
