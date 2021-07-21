#/usr/bin/python3

import sys
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    middle = -sys.maxsize
    def maxPathSumHelper(self, root: TreeNode, parent: TreeNode) -> int:
        if root is None:
            return 0
        left, right = max(self.maxPathSumHelper(root.left, root),0), max(self.maxPathSumHelper(root.right, root),0)
        self.middle = max(self.middle, root.val + left + right)
        if parent is None:
            return max(self.middle, root.val + max(left, right), root.val)
        else:
            return root.val + max(left, right)

    def maxPathSum(self, root: TreeNode) -> int:
        return self.maxPathSumHelper(root, None)

def buildTree(l):
    if len(l) == 0:
        return None
    for i in range(len(l)):
        if 2*i+1 < len(l):
            l[i].left = l[2*i+1]
        if 2*i+2 < len(l):
            l[i].right = l[2*i+2]
    return l[0]


root = buildTree(list(map(lambda s: None if s == "null" else TreeNode(int(s)), input().split(" "))))

sol = Solution()
print(sol.maxPathSum(root))
