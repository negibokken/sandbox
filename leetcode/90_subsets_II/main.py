#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        return [[]]


arr = json.loads(input())

sol = Solution()
aprint(sol.subsetsWithDup(arr))
