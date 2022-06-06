#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def sum(self, num1: int, num2: int) -> int:
        return num1 + num2


num1 = int(input())
num2 = int(input())

sol = Solution()
print(sol.sum(num1, num2))
