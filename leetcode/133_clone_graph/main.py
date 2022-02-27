#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def __init__(self):
        self.mp = {}

    def deepClone(self, node: 'Node'):
        if not node:
            return
        if node.val not in self.mp:
            self.mp = Node()
        for neighbor in node.neighbors:
            if not neighbor.val in self.mp:
                self.mp[neighbor.val] = Node(neighbor.val)
            self.mp[node.val].neighbors.append(self.mp[neighbor.val])

    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        self.deepClone(node)
        return self.mp[node.val]


arr = json.loads(input())

nodes = [None for i in range(len(arr)+1)]
for i, ele in enumerate(arr):
    nodes[i+1] = Node(i+1, ele)

# for node in nodes:
#     if not node:
#         continue
#     print(node.val, node.neighbors)

sol = Solution()
print(sol.cloneGraph(nodes[len(arr)-1]))
