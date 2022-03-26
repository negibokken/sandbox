#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        n = len(nums)
        nums = sorted(nums)
        st = set()

        def backtrack(first, arr):
            f = "{}".format(arr)
            if not f in st:
                ans.append(arr)
                st.add(f)
            for i in range(first, n):
                arr.append(nums[i])
                backtrack(i+1, arr[:])
                arr.pop()
        backtrack(0, [])

        return ans


arr = json.loads(input())

sol = Solution()
aprint(sol.subsetsWithDup(arr))
