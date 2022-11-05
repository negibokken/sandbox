#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first=0):
            if first == n:
                output.append(nums[:])
            for i in range(first, n):
                nums[first], nums[i] = nums[i], nums[first]
                backtrack(first + 1)
                nums[first], nums[i] = nums[i], nums[first]
        output = []
        n = len(nums)
        backtrack()
        return output


arr = json.loads(input())

sol = Solution()
aprint(sol.permute(arr))
