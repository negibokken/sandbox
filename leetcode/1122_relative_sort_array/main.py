#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        ans = []
        arr = [0] * 1001
        for a in arr1:
            arr[a] += 1
        for a in arr2:
            while arr[a] > 0:
                ans.append(a)
                arr[a] -= 1
        for i in range(1, 1001):
            while arr[i] > 0:
                ans.append(i)
                arr[i] -= 1

        return ans


arr1 = json.loads(input())
arr2 = json.loads(input())

sol = Solution()
aprint(sol.relativeSortArray(arr1, arr2))
