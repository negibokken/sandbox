#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
import sys


class Solution:
    def shortestDistance(self, wordsDict: List[str], word1: str, word2: str) -> int:
        idx1, idx2 = sys.maxsize, sys.maxsize
        ans = sys.maxsize
        for i in range(len(wordsDict)):
            if wordsDict[i] == word1:
                idx1 = i
                ans = min(ans, abs(idx1-idx2))
            if wordsDict[i] == word2:
                idx2 = i
                ans = min(ans, abs(idx1-idx2))
        return ans


wordsDict = json.loads(input())
word1 = json.loads(input())
word2 = json.loads(input())

sol = Solution()
print(sol.shortestDistance(wordsDict, word1, word2))
