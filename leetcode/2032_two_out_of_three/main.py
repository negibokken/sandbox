#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        ans = set()
        st1, st2 = set(), set()
        for n in nums1:
            st1.add(n)
        for n in nums2:
            if n in st1:
                ans.add(n)
            st2.add(n)
        for n in nums3:
            if n in st1 or n in st2:
                ans.add(n)
        return list(ans)


nums1 = json.loads(input())
nums2 = json.loads(input())
nums3 = json.loads(input())

sol = Solution()
print(sol.twoOutOfThree(nums1, nums2, nums3))
