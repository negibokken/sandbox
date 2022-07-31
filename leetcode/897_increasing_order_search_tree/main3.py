#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def increasingBST(self, root, tail=None):
        if not root:
            return tail
        res = self.increasingBST(root.left, root)
        root.left = None
        root.right = self.increasingBST(root.right, tail)
        return res


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
