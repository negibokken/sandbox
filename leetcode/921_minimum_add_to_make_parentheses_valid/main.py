#!/usr/bin/python3

from typing import List
import json
from collections import deque
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans = 0
        q = deque()
        for c in s:
            if c == ')':
                if not q or q[-1] != '(':
                    ans += 1
                else:
                    q.pop()
            else:
                q.append(c)
        return ans + len(q)


s = json.loads(input())

sol = Solution()
print(sol.minAddToMakeValid(s))
