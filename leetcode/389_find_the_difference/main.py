#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        arr = [0] * 26
        for c in s:
            arr[ord(c)-ord('a')] += 1
        for c in t:
            arr[ord(c)-ord('a')] -= 1
        for i, a in enumerate(arr):
            if a == -1:
                return chr(i+ord('a'))

        return ""


s = json.loads(input())
t = json.loads(input())

sol = Solution()
print(sol.findTheDifference(s, t))
