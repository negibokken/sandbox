#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ans = {}

    def dfs(self, node, depth):
        if not node:
            return
        if not node.left:
            self.dfs(node.left, depth + 1)
        if not node.right:
            self.dfs(node.right, depth + 1)

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        return None


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.rightSideView(root))
