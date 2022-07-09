#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums = sorted(nums)
        ans = []
        for i, num in enumerate(nums):
            if num == target:
                ans.append(i)
        return ans


nums = json.loads(input())
target = int(input())

sol = Solution()
aprint(sol.targetIndices(nums, target))
