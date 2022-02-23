#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def combine(self, n: int, k: int, arr=[]) -> List[List[int]]:
        def bactrack(first=1, curr=[]):
            if len(curr) == k:
                output.append(curr[:])
            for i in range(first, n + 1):
                curr.append(i)
                bactrack(i+1, curr)
                curr.pop()
        output = []
        bactrack()
        return output


n = int(input())
k = int(input())

sol = Solution()
aprint(sol.combine(n, k))
