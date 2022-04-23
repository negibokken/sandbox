#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        if num == 1:
            return True
        i = 1
        n = num//2
        while i <= n:
            if i*i == num:
                return True
            i += 1
        return False


num = int(input())
sol = Solution()
print(sol.isPerfectSquare(num))
