#!/usr/bin/python3

from typing import List
import json
from bplib.butil import aprint


class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = []
        ans.extend(nums)
        ans.extend(nums)
        return ans


arr = json.loads(input())

sol = Solution()
aprint(sol.getConcatenation(arr))
