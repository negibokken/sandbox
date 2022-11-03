#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less = []
        greater = []
        pivots = []
        for n in nums:
            if n < pivot:
                less.append(n)
            elif n > pivot:
                greater.append(n)
            else:
                pivots.append(n)
        return less + pivots + greater


arr = json.loads(input())
pivot = json.loads(input())

sol = Solution()
aprint(sol.pivotArray(arr, pivot))
