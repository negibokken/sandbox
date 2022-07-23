#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        seq = []
        t = 0
        for i in range(k-1):
            t += calories[i]
        for i in range(k-1, len(calories)):
            if i - k >= 0:
                t -= calories[i-k]
            t += calories[i]
            seq.append(t)
        print(seq)
        point = 0
        for s in seq:
            if s < lower:
                point -= 1
            if s > upper:
                point += 1

        return point


arr = json.loads(input())
nodes = list(map(arr2TreeNode, arr))
root = btreeconnect(nodes)

sol = Solution()
