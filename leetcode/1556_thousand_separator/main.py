#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def thousandSeparator(self, n: int) -> str:
        i = 0
        s = ""
        while n > 0:
            print(n % 10)
            s = chr(n % 10) + s
            n //= 10
            i += 1
            if i % 2 == 0 and n != 0:
                s = '.' + s

        return s


n = int(input())

sol = Solution()
print(sol.thousandSeparator(n))
