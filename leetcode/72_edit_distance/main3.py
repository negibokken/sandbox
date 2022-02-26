#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)

        if n*m == 0:
            return n+m

        d = [[0]*(m+1)for _ in range(n+1)]

        for i in range(n+1):
            d[i][0] = i
        for j in range(m+1):
            d[0][j] = j

        for i in range(1, n+1):
            for j in range(1, m+1):
                if word1[i-1] == word2[j-1]:
                    d[i][j] = min(d[i-1][j]+1,  d[i][j-1]+1, d[i-1][j-1])
                else:
                    d[i][j] = min(d[i-1][j],  d[i][j-1], d[i-1][j-1]) + 1
        return d[n][m]


word1 = input()
word2 = input()

sol = Solution()
print(sol.minDistance(word1, word2))
