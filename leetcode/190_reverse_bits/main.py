#!/usr/bin/python3

from typing import List
import json


class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        i = 0
        while i < 32:
            ans <<= 1
            if n & 1:
                ans |= 1
            n >>= 1
            i += 1
        return ans


s = input()
n = 0
for c in s:
    n <<= 1
    if c == '1':
        n += 1

sol = Solution()
print(sol.reverseBits(n))
