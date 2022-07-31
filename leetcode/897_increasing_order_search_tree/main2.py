#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def __init__(self):
        self.preNode = None

    def inorder(self, root: TreeNode) -> Optional[TreeNode]:
        if not root:
            return None
        self.inorder(root.left)
        self.preNode.right = root
        root.left = None
        self.preNode = root
        self.inorder(root.right)

    def increasingBST(self, root: TreeNode) -> TreeNode:
        blank = TreeNode()
        self.preNode = blank
        self.inorder(root)
        return blank.right


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
