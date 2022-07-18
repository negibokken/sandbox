#!/usr/bin/python3

from typing import List, Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def __init__(self):
        self.mp = dict()
        self.depth = 0

    def dfs(self, node: Optional[TreeNode], depth: int):
        if not node:
            return
        self.depth = max(self.depth, depth)
        if depth not in self.mp:
            self.mp[depth] = []
        self.mp[depth].append(node.val)
        self.dfs(node.left, depth+1)
        self.dfs(node.right, depth+1)

    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        self.dfs(root, 0)
        ans = []
        for i in range(self.depth+1):
            ans.append(sum(self.mp[i]) / len(self.mp[i]))
        return ans


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
aprint(sol.averageOfLevels(root))
