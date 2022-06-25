#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint


class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        word_num = len(words)
        space_num = text.count(' ')
        gap = 0 if word_num == 1 else space_num // (word_num-1)
        trailing_space = space_num - gap * (word_num-1)
        return (' ' * gap).join(words) + ' ' * trailing_space


text = json.loads(input())

sol = Solution()
print(sol.reorderSpaces(text))
