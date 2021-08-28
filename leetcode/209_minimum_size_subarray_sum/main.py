#!/usr/bin/python3

from typing import List
import json
import sys


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = sys.maxsize
        sum = 0
        i, j = 0, 0
        while i < len(nums):
            while sum >= target:
                sum += nums[i]
                i += 1
            j = i
            while sum < target and j < len(nums):
                sum -= nums[j]
                j += 1
            if sum >= target:
                print(sum, i, j)
                ans = min(ans, j - i)
        return 0 if ans == sys.maxsize else ans


target = int(input())
arr = json.loads(input())

sol = Solution()
print(sol.minSubArrayLen(target, arr))
