#!/usr/bin/python3

from typing import List
from bplib.butil import aprint


class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        lo, hi = 0, len(s)
        ans = []
        for x in s:
            if x == 'I':
                ans.append(lo)
                lo += 1
            else:
                ans.append(hi)
                hi -= 1
        return ans + [lo]


s = input()
sol = Solution()
aprint(sol.diStringMatch(s))
