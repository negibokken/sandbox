#!/usr/bin/python3

from typing import Optional, Set
import json
import sys


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, root: Optional[TreeNode]) -> Set[int]:
        if root.left is None and root.right is None:
            return {root.val}
        return self.helper(root.left).union(self.helper(root.right))

    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        ans = sorted([x for x in self.helper(root)])
        if len(ans) < 2:
            return -1
        return ans[1]


def connect(nodes):
    for i in range(len(nodes)):
        if 2*i+1 < len(nodes):
            nodes[i].left = nodes[2*i+1]
        if 2*i+2 < len(nodes):
            nodes[i].right = nodes[2*i+2]
    return nodes[0]


def rec(root):
    if root is None:
        return
    rec(root.left)
    print(root.val)
    rec(root.right)


def tonode(val):
    if val is None:
        return None
    return TreeNode(val)


arr = list(map(tonode, json.loads(input())))
root = connect(arr)

sol = Solution()
print(sol.findSecondMinimumValue(root))
