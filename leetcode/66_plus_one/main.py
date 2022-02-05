#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        carry = 1
        while i >= 0:
            digits[i] += carry
            carry = digits[i] // 10
            digits[i] = digits[i] % 10
            i -= 1
        if carry:
            digits.insert(0, 1)
        return digits


arr = json.loads(input())

sol = Solution()
print("{}".format(sol.plusOne(arr)).replace(" ", ""))
