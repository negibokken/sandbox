#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class Solution:

    def isPerfectSquare(self, num: int) -> bool:
        if num == 1:
            return True
        left, right = 0, num//2,
        while left <= right:
            mid = left + (right-left)//2
            m = mid*mid
            if m == num:
                return True
            elif m > num:
                right = mid - 1
            else:
                left = mid + 1

        return False


num = int(input())
sol = Solution()
print(sol.isPerfectSquare(num))
