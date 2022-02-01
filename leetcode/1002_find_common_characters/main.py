#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect
import collections


class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        res = collections.Counter(words[0])
        for a in words:
            res &= collections.Counter(a)
            print(res)
        return list(res.elements())


arr = json.loads(input())

sol = Solution()
print("{}".format(sol.commonChars(arr)).replace(" ", ""))
