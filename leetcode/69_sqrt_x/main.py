#!/usr/bin/python3

import json


class Solution:
    def mySqrt(self, x: int) -> int:
        i = 0
        while (i*i) <= x:
            i += 1
        return i - 1


x = int(input())

sol = Solution()
print(sol.mySqrt(x))
