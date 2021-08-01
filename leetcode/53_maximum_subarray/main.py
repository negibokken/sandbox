#!/usr/bin/python3

from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i-1] > 0:
                nums[i] += nums[i-1]
        return max(nums)


sol = Solution()
nums = list(map(int, input().split(" ")))
print(sol.maxSubArray(nums))
