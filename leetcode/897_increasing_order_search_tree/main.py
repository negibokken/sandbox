#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def __init__(self):
        self.nodes = []

    def inorder(self, root: TreeNode):
        if not root:
            return
        self.inorder(root.left)
        self.nodes.append(root)
        self.inorder(root.right)

    def increasingBST(self, root: TreeNode) -> TreeNode:
        self.inorder(root)

        r = None
        prev = None
        for node in self.nodes:
            node.left = None
            node.right = None

            if not prev:
                prev = node
                r = node
                continue

            prev.right = node
            prev = node

        return r


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

arr = []


def traverseRight(node):
    if not node:
        return
    arr.append(node.val)
    traverseRight(node.right)


sol = Solution()
traverseRight(sol.increasingBST(root))
aprint(arr)
