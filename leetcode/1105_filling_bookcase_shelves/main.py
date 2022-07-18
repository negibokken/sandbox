#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        return 0


books = json.loads(input())
shelfWidth = int(input())

sol = Solution()
print(sol.minHeightShelves(books, shelfWidth))
