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
    def helper(self, digits, i, s) -> [str]:
        if len(digits) == 0:
            return []
        if i == len(digits) or i == -1:
            return [s]
        ans = []
        for n in chars[int(digits[i])]:
            ans = ans + self.helper(digits, i+1, s + n)
        return ans

    def letterCombinations(self, digits) -> [str]:
        return self.helper(digits, 0, '')


str = json.loads(input())

sol = Solution()
print(sol.letterCombinations(str))
