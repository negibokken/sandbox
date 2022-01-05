#!/usr/bin/python3


class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        ans = 0
        i = 0
        while n > 0:
            if not n & 1:
                ans += 2**i
            n >>= 1
            i += 1
        return ans


n = int(input())

sol = Solution()
print(sol.bitwiseComplement(n))
