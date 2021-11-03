#!/usr/bin/python3

from typing import List
import json
import sys


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = sys.maxsize
        i, j, sum = 0, 0, 0
        while i < len(nums):
            while sum < target and j < len(nums):
                sum += nums[j]
                j += 1
            if sum < target:
                i += 1
                continue
            while sum >= target:
                ans = min(ans, j - i)
                sum -= nums[i]
                i += 1
        return ans if ans is not sys.maxsize else 0

target = int(input())
arr = json.loads(input())

sol = Solution()
print(sol.minSubArrayLen(target, arr))