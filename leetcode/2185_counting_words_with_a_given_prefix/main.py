#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return sum(w.find(pref) == 0 for w in words)


arr = json.loads(input())
pref = json.loads(input())

sol = Solution()
print(sol.prefixCount(arr, pref))
