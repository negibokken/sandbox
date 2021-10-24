#!/usr/bin/python3

from bplib.butil import TreeNode, arr2TreeNode, btreeconnect
from typing import List
import json
import sys


class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            c = True
            prev = -sys.maxsize
            for j in range(n):
                if prev > nums[(i+j) % n]:
                    c = False
                    break
                prev = nums[(i+j) % n]
            if c:
                return True
        return False


arr = json.loads(input())

sol = Solution()
print("true" if sol.check(arr) else "false")
