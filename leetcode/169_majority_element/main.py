#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)
        mp = {}
        for num in nums:
            if num not in mp:
                mp[num] = 0
            mp[num] += 1
            if mp[num] > (n//2):
                return num
        return 0


arr = json.loads(input())

sol = Solution()
print(sol.majorityElement(arr))
