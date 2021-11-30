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
    def helper(self, root: Optional[TreeNode], parent: Optional[TreeNode], leaves: List[int]) -> bool:
        if not root:
            return
        if not root.left and not root.right:
            leaves.append(root.val)
            if not parent:
                return False
            if parent.left == root:
                parent.left = None
            else:
                parent.right = None
            return True
        self.helper(root.left, root, leaves)
        self.helper(root.right, root, leaves)
        return True

    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans = []
        while 1:
            arr = []
            f = self.helper(root, None, arr)
            ans.append(arr)
            if not f:
                break
        return ans


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.findLeaves(root))
