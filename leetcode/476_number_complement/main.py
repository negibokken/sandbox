#!/usr/bin/python3

class Solution:
    def findComplement(self, num: int) -> int:
        ans, ind = 0, 0
        while num > 0:
            if not (num & 1):
                ans += (2 ** ind)
            ind += 1
            num >>= 1
        return ans


num = int(input())

sol = Solution()
print(sol.findComplement(num))
