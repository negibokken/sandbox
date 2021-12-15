#!/usr/bin/python3

from typing import List
import json


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        v = {}
        for p in paths:
            v[p[0]] = p[1]
        cur = paths[0][0]
        while cur in v:
            cur = v[cur]
        return cur


arr = json.loads(input())

sol = Solution()
print(sol.destCity(arr))
