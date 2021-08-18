#!/usr/bin/python3

import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def goodNodesHelper(self, root: TreeNode, maxValue: int) -> int:
        if root is None:
            return 0
        maxValue = max(maxValue, root.val)
        val = 1 if root.val >= maxValue else 0
        return self.goodNodesHelper(root.left, maxValue) + self.goodNodesHelper(root.right, maxValue) + val

    def goodNodes(self, root: TreeNode) -> int:
        if root is None:
            return 1
        return self.goodNodesHelper(root, root.val)


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
print(sol.goodNodes(root))
