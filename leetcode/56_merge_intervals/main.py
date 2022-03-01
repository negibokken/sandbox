#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        st = set()
        for interval in intervals:
            for i in range(interval[0], interval[1]+1):
                st.add(i)
        ans = []
        arr = list(st)
        i = 0
        while i < len(arr):
            start = arr[i]
            end = None
            while i + 1 < len(arr) and arr[i] + 1 == arr[i+1]:
                end = arr[i+1]
                i += 1
            i += 1
            ans.append([start, end])

        return ans


arr = json.loads(input())

sol = Solution()
aprint(sol.merge(arr))
