#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint

chars = [
    [],
    [], ['a', 'b', 'c'], ['d', 'e', 'f'],
    ['g', 'h', 'i'], ['j', 'k', 'l'], ['m', 'n', 'o'],
    ['p', 'q', 'r'], ['t', 'u', 'v'], ['w', 'x', 'y', 'z']
]


class Solution:
    def helper(self, digits, i) -> [str]:
        arr = []
        for n in chars[int(digits[i])]:
            arr.append(n)
        return arr

    def letterCombinations(self, digits) -> [str]:
        self.helper(digits, 0)


str = json.loads(input())

sol = Solution()
print(sol.letterCombinations(str))
