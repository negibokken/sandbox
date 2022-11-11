#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        for num in nums:
            nums[abs(num)-1] *= -1
        ans = []
        for num in nums:
            if nums[abs(num)-1] > 0:
                ans.append(abs(num))
                nums[abs(num)-1] *= -1
        return ans


arr = json.loads(input())

sol = Solution()
aprint(sorted(sol.findDuplicates(arr)))
