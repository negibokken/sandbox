#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:

    def __init__(self):
        self.memo = set()

    def isHappy(self, n: int) -> bool:
        if n in self.memo:
            return False
        self.memo.add(n)
        sum = 0
        while n > 0:
            d = n % 10
            sum += (d*d)
            n = n // 10
        if sum == 1:
            return True
        return self.isHappy(sum)


n = int(input())

sol = Solution()
print(sol.isHappy(n))
