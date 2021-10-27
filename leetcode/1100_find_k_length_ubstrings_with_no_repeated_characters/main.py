#!/usr/bin/python3

import json


class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        ans = 0
        for i in range(len(s)):
            f = True
            mp = {}
            if i + k > len(s):
                continue
            for j in range(i, min(i + k, len(s))):
                if s[j] in mp:
                    f = False
                    break
                mp[s[j]] = True
            if f:
                ans += 1
        return ans


s = input().rstrip("\n")
k = int(input())

sol = Solution()
print(sol.numKLenSubstrNoRepeats(s, k))
