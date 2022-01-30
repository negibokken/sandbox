#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        st = {}
        for n in nums1:
            if n not in st:
                st[n] = 0
            st[n] += 1
        ans = []
        for n in nums2:
            if n in st and st[n] > 0:
                st[n] -= 1
                ans.append(n)
        return ans


arr1 = json.loads(input())
arr2 = json.loads(input())

sol = Solution()
print(sol.intersect(arr1, arr2))
