#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans, cnt = 0, 0
        for i in range(len(nums)):
            if nums[i] == 1:
                cnt += 1
                ans = max(ans, cnt)
            else:
                cnt = 0
        return ans


arr = json.loads(input())

sol = Solution()
print(sol.findMaxConsecutiveOnes(arr))
