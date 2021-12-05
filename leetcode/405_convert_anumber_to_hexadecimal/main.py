#!/usr/bin/python3


class Solution:
    letters = [
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f'
    ]

    def toHex(self, num: int) -> str:
        temp = num if num >= 0 else (2 ** 32 + num)
        if temp == 0:
            return "0"
        ans = ""
        while temp > 0:
            ans = self.letters[int((temp % 16))] + ans
            temp //= 16
        return ans


num = int(input())
sol = Solution()
print(sol.toHex(num))
