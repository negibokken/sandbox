#!/usr/bin/python3


class Solution:
    def addDigits(self, num: int) -> int:
        while num >= 10:
            t = 0
            while num > 0:
                t += num % 10
                num //= 10
            num = t
        return num


n = int(input())

sol = Solution()
print(sol.addDigits(n))
