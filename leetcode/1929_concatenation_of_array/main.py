#!/usr/bin/python3

from typing import List
import json
from bplib.butil import aprint


class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = [0] * (2*len(nums))
        for i in range(2*len(nums)):
            ans[i] = nums[(i % len(nums))]
        return ans


arr = json.loads(input())

sol = Solution()
aprint(sol.getConcatenation(arr))
