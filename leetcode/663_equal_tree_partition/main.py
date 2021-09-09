#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        return 1


arr = json.loads(input())
nodes = map(arr2TreeNode, arr)
root = btreeconnect(nodes)

sol = Solution()
