#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def checkRecord(self, s: str) -> bool:
        absents = s.count('A')
        if absents >= 2:
            return False
        if "LLL" in s:
            return False
        return True


str = (input())

sol = Solution()
print(sol.checkRecord(str))
