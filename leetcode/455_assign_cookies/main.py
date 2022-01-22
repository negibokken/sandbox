#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)

        ans = 0
        i = 0
        for gg in g:
            while i < len(s) and gg > s[i]:
                i += 1
            if i >= len(s):
                break
            if gg <= s[i]:
                ans += 1
                i += 1
        return ans


g = json.loads(input())
s = json.loads(input())


sol = Solution()
print(sol.findContentChildren(g, s))
