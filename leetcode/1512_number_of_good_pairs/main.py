#!/usr/bin/python3

from typing import List
import json
import math


def combinations(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        mp = {}
        for n in nums:
            if n not in mp:
                mp[n] = 0
            mp[n] += 1
        ans = 0
        for k, v in mp.items():
            if v > 1:
                ans += combinations(v, 2)
        return ans


arr = json.loads(input())

sol = Solution()
print(sol.numIdenticalPairs(arr))
