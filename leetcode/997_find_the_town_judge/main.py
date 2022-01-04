#!/usr/bin/python3

from typing import List
import json


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        return 0


n = int(input())
trust = json.loads(input())

sol = Solution()
print(sol.findJudge(n, trust))
