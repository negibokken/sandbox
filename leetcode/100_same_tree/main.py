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
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:
            return True
        if not (p and q):
            return False
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
p = btreeconnect(nodes)

arr2 = json.loads(input())
nodes2 = list(map(arr2TreeNode, arr2))
q = btreeconnect(nodes2)

sol = Solution()
print(sol.isSameTree(p, q))
