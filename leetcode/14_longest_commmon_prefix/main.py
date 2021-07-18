#/usr/bin/python3

import sys
from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        m = 500
        for str in strs:
            m  = min(m, len(str))

        for i in range(m):
            t = "*"
            for s in strs:
                if s[i] != t and t != "*":
                    return s[:i]
                t = s[i]
        return strs[0][:m]

st = []
for line in sys.stdin:
    st = line.rstrip("\n ").split(" ")

s = Solution()
print(s.longestCommonPrefix(st))
