#!/usr/bin/python3

from typing import List
import json


class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums) <= 4:
            return 0
        nums.sort()
        ans = min(
                nums[-1] - nums[3],
                nums[-2] - nums[2],
                nums[-3] - nums[1],
                nums[-4] - nums[0],
        )
        return ans


arr = json.loads(input())
sol = Solution()
print(sol.minDifference(arr))
