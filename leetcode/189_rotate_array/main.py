#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        a = [0] * n
        for i in range(n):
            a[(i+k) % n] = nums[i]
        nums[:] = a


arr = json.loads(input())
k = int(input())

sol = Solution()
sol.rotate(arr, k)
aprint(arr)
