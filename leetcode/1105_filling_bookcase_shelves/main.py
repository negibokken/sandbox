#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        n = len(books)
        dp = [float('inf') for _ in range(n+1)]
        dp[0] = 0
        for i in range(1, n + 1):
            max_width = shelfWidth
            max_height = 0
            j = i - 1
            while j >= 0 and max_width - books[j][0] >= 0:
                max_width -= books[j][0]
                max_height = max(max_height, books[j][1])
                dp[i] = min(dp[i], dp[j]+max_height)
                j -= 1
        return dp[n]


books = json.loads(input())
shelfWidth = int(input())

sol = Solution()
print(sol.minHeightShelves(books, shelfWidth))
