#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect
import sys


class Solution:

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        arr = []

        def dfs(node):
            if node.left:
                dfs(node.left)
            arr.append(node.val)
            if node.right:
                dfs(node.right)
        dfs(root)
        return min(b - a for a, b in zip(arr, arr[1:]))


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.getMinimumDifference(root))
