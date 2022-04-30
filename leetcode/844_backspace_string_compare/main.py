#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def backSaced(self, s) -> str:
        ss = ""
        skip = 0
        for i in range(len(s)-1, -1, -1):
            if skip > 0 and s[i] != '#':
                skip -= 1
                continue
            if s[i] == '#':
                skip += 1
                continue
            ss = s[i] + ss
        return ss

    def backspaceCompare(self, s: str, t: str) -> bool:
        return self.backSaced(s) == self.backSaced(t)


str1 = json.loads(input())
str2 = json.loads(input())

sol = Solution()
print(sol.backspaceCompare(str1, str2))
