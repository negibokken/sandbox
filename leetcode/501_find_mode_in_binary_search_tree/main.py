#!/usr/bin/python3

import sys
from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import queue


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        q = queue.Queue()
        q.put(root)
        mp = {}
        mx = -1
        while not q.empty():
            node = q.get()
            if not node:
                continue
            q.put(node.left)
            q.put(node.right)
            if node.val not in mp:
                mp[node.val] = 0
            mp[node.val] += 1
            mx = max(mx, mp[node.val])
        ans = []
        for k, v in mp.items():
            if v == mx:
                ans.append(k)
        return ans


def dfs(root, parent=None):
    if not root:
        return
    dfs(root.left, root)
    if parent:
        print("parent: ", parent.id, end=" ")
    else:
        print("parent: None", end=" ")
    print("id:", root.id)
    dfs(root.right, root)


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)
sol = Solution()
print("{}".format(sol.findMode(root)))
