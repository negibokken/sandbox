#!/usr/bin/python3

import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect
import sys


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode, maxValue=-sys.maxsize) -> int:
        if not root:
            return 0
        ans = 0
        if root.val >= maxValue:
            ans += 1
        mx = max(root.val, maxValue)
        return ans + self.goodNodes(root.left, mx) + self.goodNodes(root.right, mx)


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.goodNodes(root))
