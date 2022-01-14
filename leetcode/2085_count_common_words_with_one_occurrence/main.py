#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        mp = {}
        for w in words1:
            if w not in mp:
                mp[w] = 0
            mp[w] += 1
        mp2 = {}
        for w in words2:
            if w not in mp2:
                mp2[w] = 0
            mp2[w] += 1
        ans = 0
        for k, v in mp2.items():
            if v != 1:
                continue
            if k in mp and mp[k] == 1:
                ans += 1
        return ans


arr1 = json.loads(input())
arr2 = json.loads(input())

sol = Solution()
print(sol.countWords(arr1, arr2))
