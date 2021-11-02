#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        diff = abs(max(nums) - min(nums))
        if diff == 0:
            return 0
        else:
            return max(diff - 2 * k, 0)


arr = json.loads(input())
k = int(input())

sol = Solution()
print(sol.smallestRangeI(arr, k))
