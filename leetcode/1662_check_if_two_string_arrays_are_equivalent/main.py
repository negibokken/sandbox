#!/usr/bin/python3

from typing import List
import json


class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return "".join(word1) == "".join(word2)


arr1 = json.loads(input())
arr2 = json.loads(input())

sol = Solution()
print("true" if sol.arrayStringsAreEqual(arr1, arr2) else "false")
