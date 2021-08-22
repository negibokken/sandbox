#!/usr/bin/python3

from typing import List
import json


class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            if (i % 2 == 0) and nums[i] != 0:
                j = i+1
                while j < len(nums) and (nums[j] % 2) == 0:
                    j += 2
                if (j % 2 != 0) and nums[j] == 0:
                    nums[i], nums[j] = nums[j], nums[i]
            elif (i % 2 == 1) and (nums[i] % 2) != 1:
                j = i + 1
                while j < len(nums) and (nums[j] % 2) == 0:
                    j += 2
            nums[i], nums[j] = nums[j], nums[i]
        return nums


arr = json.loads(input())

sol = Solution()
print(sol.sortArrayByParityII(arr))
