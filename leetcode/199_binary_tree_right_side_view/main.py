#!/usr/bin/python3

from typing import List, Optional
import json
from collections import deque
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        next_level = deque([root, ])
        right_side = []

        while next_level:
            cur_level = next_level
            next_level = deque()
            while cur_level:
                node = cur_level.popleft()
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            right_side.append(node.val)
        return right_side


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.rightSideView(root))
