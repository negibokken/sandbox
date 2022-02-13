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
        self.count = 0

    def helper(self, node):
        if not node:
            return 0
        left, right = self.helper(node.left), self.helper(node.right)
        if node.val == left + right:
            self.count += 1
        return node.val + left + right

    def equalToDescendants(self, root: Optional[TreeNode]) -> int:
        self.helper(root)
        return self.count


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)


def walk(root):
    if not root:
        return
    print(root.val)
    walk(root.left)
    walk(root.right)


walk(root)


sol = Solution()
print(sol.equalToDescendants(root))
