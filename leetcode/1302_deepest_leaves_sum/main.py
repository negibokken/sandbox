#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.maximumDepth = 0
        self.sum = 0

    def bfs(self, root: Optional[TreeNode], depth: int):
        if not root:
            return
        self.maximumDepth = max(self.maximumDepth, depth)
        self.bfs(root.left, depth+1)
        self.bfs(root.right, depth+1)

    def sumDeepestLeaves(self, root: Optional[TreeNode], depth: int):
        if not root:
            return
        if depth == self.maximumDepth:
            self.sum += root.val
        self.sumDeepestLeaves(root.left, depth + 1)
        self.sumDeepestLeaves(root.right, depth+1)

    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        self.bfs(root, 0)
        self.sumDeepestLeaves(root, 0)
        return self.sum


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.deepestLeavesSum(root))
