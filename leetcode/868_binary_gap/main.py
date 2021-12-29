#!/usr/bin/python3

from typing import List
import json


class Solution:
    def binaryGap(self, n: int) -> int:
        ans = 0
        while n > 0:
            if n & 1:
                n >>= 1

                if n & 1:
                    ans = max(ans, 1)
                    continue

                tmp, last = 1, 1
                while n > 0 and not (n & 1):
                    tmp += 1
                    last = (n & 1)
                    n >>= 1
                if last != 0:
                    continue
                ans = max(ans, tmp)
            else:
                n >>= 1
        return ans


n = int(input())

sol = Solution()
print(sol.binaryGap(n))
