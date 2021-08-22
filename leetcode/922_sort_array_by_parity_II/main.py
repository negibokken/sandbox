#!/usr/bin/python3

from typing import List
import json


class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            if (i % 2 == 0) and nums[i] != 0:
                for j in range(len(nums)):
                    if (j % 2 != 0) and nums[j] == 0:
                        nums[i], nums[j] = nums[j], nums[i]
            elif (i % 2 == 1) and (nums[i] % 2) != 1:
                for j in range(len(nums)):
                    if (j % 2 != 1) and (nums[j] % 2) == 1:
                        nums[i], nums[j] = nums[j], nums[i]
        return nums


arr = json.loads(input())

sol = Solution()
print(sol.sortArrayByParityII(arr))
