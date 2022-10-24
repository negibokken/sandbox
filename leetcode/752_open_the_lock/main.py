#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys

inf = sys.maxsize


class Solution:
    def helper(self, deadendSet, target, current, n) -> int:
        if current in deadendSet:
            return inf
        if (n != 0) and (current == "0000"):
            return inf
        if current == target:
            return n
        ans = inf
        for i in [-1, 1]:
            for j in [0, 1, 2, 3]:
                num = int(current[j])
                nextlock = current
                nx = (num + 10 + i) % 10
                nextlock = nextlock[:j] + chr(nx + 48) + nextlock[j+1:]
                ans = min(ans, self.helper(deadendSet, target, nextlock, n+1))
        return ans

    def openLock(self, deadends: List[str], target: str) -> int:
        s = set(deadends)
        ans = self.helper(s, target, "0000", 0)
        if ans == inf:
            return -1
        return ans


arr = json.loads(input())
target = json.loads(input())

sol = Solution()
print(sol.openLock(arr, target))
