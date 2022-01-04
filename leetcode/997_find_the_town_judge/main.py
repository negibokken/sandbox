#!/usr/bin/python3

from typing import List
import json


class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        people = [[0, 0] for i in range(n)]
        for t in trust:
            people[t[0]-1][0] += 1
            people[t[1]-1][1] += 1
        for i, p in enumerate(people):
            if p[0] == 0 and p[1] == n - 1:
                return i+1
        return -1


n = int(input())
trust = json.loads(input())

sol = Solution()
print(sol.findJudge(n, trust))
