#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def isThree(self, n: int) -> bool:
        cnt = 1
        for i in range(1, n//2+1):
            if (n % i == 0):
                cnt += 1
        return cnt == 3


n = int(input())

sol = Solution()
print(sol.isThree(n))
