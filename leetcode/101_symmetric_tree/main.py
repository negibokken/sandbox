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
    def isSame(self, left, right):
        if (not right and left) or (right and not left):
            return False
        elif not right and not left:
            return True
        else:
            if left.val != right.val:
                return False
            return self.isSame(left.left, right.right) and self.isSame(left.right, right.left)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return False
        return self.isSame(root.left, root.right)


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.isSymmetric(root))
