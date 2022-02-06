#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ans = 0
        i = len(s) - 1
        while i >= 0:
            if s[i] == ' ':
                i -= 1
                continue
            while i >= 0 and s[i] != ' ':
                ans += 1
                i -= 1
            break
        return ans


str = json.loads(input())
sol = Solution()
print(sol.lengthOfLastWord(str))
