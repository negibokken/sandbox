#!/usr/bin/python3

from typing import Optional
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def checkEqualTree(self, root: Optional[TreeNode]) -> bool:
        def sum(node):
            if not node:
                return 0
            s = node.val + sum(node.left) + sum(node.right)
            if node is not root:
                cuts.add(s)
            return s
        cuts = set()
        return sum(root) / 2 in cuts


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
ans = sol.checkEqualTree(root)
print("true" if ans else "false")
