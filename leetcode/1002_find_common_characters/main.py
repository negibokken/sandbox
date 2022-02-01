#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        if len(words) == 0:
            return []
        dicts = [{} for i in range(len(words))]
        for i, word in enumerate(words):
            for c in word:
                if c not in dicts[i]:
                    dicts[i][c] = 0
                dicts[i][c] += 1
        ans = []
        for c, num in dicts[0].items():
            minVal = num
            isAllContains = True
            for i in range(1, len(words)):
                if c not in dicts[i]:
                    isAllContains = False
                    break
                else:
                    minVal = min(minVal, dicts[i][c])
            if not isAllContains:
                continue
            for i in range(minVal):
                ans.append(c)
        return ans


arr = json.loads(input())

sol = Solution()
print("{}".format(sol.commonChars(arr)).replace(" ", ""))
