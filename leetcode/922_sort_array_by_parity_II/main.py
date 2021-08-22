#!/usr/bin/python3

from typing import List
import json


class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        N = len(nums)
        ans = [0] * N

        t = 0
        for x in nums:
            if x % 2 == 0:
                ans[t] = x
                t += 2
        t = 1
        for x in nums:
            if x % 2 == 1:
                ans[t] = x
                t += 2
        return ans





arr = json.loads(input())

sol = Solution()
print(sol.sortArrayByParityII(arr))
