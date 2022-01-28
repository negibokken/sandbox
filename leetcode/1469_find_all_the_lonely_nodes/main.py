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
    def getLonelyNodes(self, root: Optional[TreeNode]) -> List[int]:
        arr = []

        def walk(root):
            if not root:
                return
            if root.left and not root.right:
                arr.append(root.left.val)
            if not root.left and root.right:
                arr.append(root.right.val)
            walk(root.left)
            walk(root.right)

        walk(root)
        return arr


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print("{}".format(sol.getLonelyNodes(root)).replace(" ", ""))
