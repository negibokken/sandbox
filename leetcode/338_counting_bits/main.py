#!/usr/bin/python3

from typing import List


class Solution:
    def popCount(self, n):
        cnt = 0
        while n > 0:
            if n & 1:
                cnt += 1
            n = n >> 1
        return cnt

    def countBits(self, n: int) -> List[int]:
        ans = []
        for i in range(n+1):
            ans.append(self.popCount(i))
        return ans


n = int(input())

sol = Solution()
print(sol.countBits(n))
