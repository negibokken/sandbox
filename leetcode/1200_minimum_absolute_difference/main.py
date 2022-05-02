#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr = sorted(arr)
        mindiff = sys.maxsize
        for i in range(len(arr)-1):
            mindiff = min(arr[i+1]-arr[i], mindiff)
        ans = []
        for i in range(len(arr)-1):
            if arr[i+1] - arr[i] == mindiff:
                ans.append([arr[i], arr[i+1]])
        return ans


arr = json.loads(input())

sol = Solution()
aprint(sol.minimumAbsDifference(arr))
