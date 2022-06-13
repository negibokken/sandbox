#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
