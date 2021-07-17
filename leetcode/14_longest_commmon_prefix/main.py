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
            for s in str:
                print(s[i])
                if s[i] != t and t != "*":
                    print(">{}<".format(s[:i]))
                    return s[:i]
                t = s[i]
        return ""
        

st = []
for line in sys.stdin:
    st = line.rstrip("\n ").split(" ")

s = Solution()
s.longestCommonPrefix(st)
