#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return 1


arr = json.loads(input())

sol = Solution()
print(sol.maxSubArray(arr))
