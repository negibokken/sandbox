#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr = sorted(arr)
        diff = None
        prev = None
        for a in arr:
            if prev == None:
                prev = a
                continue
            if diff == None:
                diff = a-prev
            else:
                if a-prev != diff:
                    return False
            prev = a

        return True


arr = json.loads(input())

sol = Solution()
print(sol.canMakeArithmeticProgression(arr))
