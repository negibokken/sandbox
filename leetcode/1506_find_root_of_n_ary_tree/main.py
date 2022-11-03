#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
from collections import deque


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []


class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        st = set([t.val for t in tree])
        for node in tree:
            for child in node.children:
                st.remove(child.val)

        for node in tree:
            if node.val in st:
                return node
        return None


arr = json.loads(input())
nodes = []
q = deque([Node(arr[0])])
i = 2
while q:
    node = q.popleft()
    while i < len(arr) and arr[i] is not None:
        n = Node(arr[i])
        node.children.append(n)
        q.append(n)
        i += 1
    nodes.append(node)
    i += 1

sol = Solution()
print(sol.findRoot(nodes).val)
