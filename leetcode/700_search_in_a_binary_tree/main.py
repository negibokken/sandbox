#!/usr/bin/python3

from typing import Optional
import json
from queue import Queue


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return None

        if root.val == val:
            return root
        elif root.val < val:
            return self.searchBST(root.right, val)
        else:
            return self.searchBST(root.left, val)


def connect(arr):
    if len(arr) == 0:
        return None
    for i in range(len(arr)):
        if 2*i+1 < len(arr):
            arr[i].left = arr[2*i+1]
        if 2*i+2 < len(arr):
            arr[i].right = arr[2*i+2]
    return arr[0]


def i2TreeNode(ele):
    if ele is None:
        return None
    return TreeNode(ele)


def bst(root):
    ans = []
    q = Queue()
    q.put(root)
    while q.empty() is False:
        node = q.get()
        if node is None:
            continue
        ans.append(node.val)

        if node.left is None and node.right is None:
            continue
        elif node.right is None:
            q.put(node.left)
            continue
        else:
            q.put(node.left)
            q.put(node.right)
    return ans


arr = json.loads(input())
arrN = list(map(i2TreeNode, arr))
val = int(input())
root = connect(arrN)
sol = Solution()
print(bst(sol.searchBST(root, val)))
