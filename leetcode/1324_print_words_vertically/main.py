#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def printVertically(self, s: str) -> List[str]:
        splited = s.split(" ")
        maxLength = max(map(len, splited))
        ans = [""] * maxLength
        for s in splited:
            i = 0
            while i < maxLength:
                if i < len(s):
                    ans[i] += s[i]
                else:
                    ans[i] += ' '
                i += 1
        for i in range(len(ans)):
            ans[i] = ans[i].rstrip(' ')

        return ans


s = json.loads(input())

sol = Solution()
print(sol.printVertically(s))
