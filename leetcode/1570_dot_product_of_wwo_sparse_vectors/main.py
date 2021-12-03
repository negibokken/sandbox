#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, dbg


class SparseVector:

    def __init__(self, nums: List[int]):
        self.nums = dict()
        for i, n in enumerate(nums):
            if n:
                self.nums[i] = n

    def dotProduct(self, vec: 'SparseVector') -> int:
        ans = 0
        for i, n in self.nums.items():
            if i in vec.nums:
                ans += n * vec.nums[i]
        return ans


nums1 = json.loads(input())
nums2 = json.loads(input())

v1 = SparseVector(nums1)
v2 = SparseVector(nums2)
print(v1.dotProduct(v2))
