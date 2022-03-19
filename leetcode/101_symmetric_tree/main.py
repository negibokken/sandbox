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
def prin(a):
    if a:
        return a.val


class Solution:
    def isSame(self, left, right):
        print(left, right)
        if (not right and left) or (right and not left):
            print("here: Falsse")
            return False
        elif not right and not left:
            print("here: True")
            return True
        else:
            if left.val != right.val:
                print("False: ", left.val, right.val)
                return False
            print(left.val, right.val)
            print(">>")
            return self.isSame(left.left, right.left) and self.isSame(left.right, right.right)

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return False
        return self.isSame(root.left, root.right)


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()


def bfs(node):
    if not node:
        return
    print(node.val)
    bfs(node.left)
    bfs(node.right)


bfs(root)


# print(sol.isSymmetric(root))
