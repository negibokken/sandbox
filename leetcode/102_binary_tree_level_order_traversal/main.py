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
    def __init__(self):
        self.leveledTreeNode = []

    def helper(self, root: Optional[TreeNode], level=0):
        if not root:
            return
        if len(self.leveledTreeNode) < level + 1:
            self.leveledTreeNode.append([])
        self.leveledTreeNode[level].append(root.val)
        self.helper(root.left, level + 1)
        self.helper(root.right, level + 1)

    def levelOrder(self, root: Optional[TreeNode], level=0) -> List[List[int]]:
        self.helper(root)
        return self.leveledTreeNode


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.levelOrder(root))
