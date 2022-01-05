#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect


class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        st = set([char for char in brokenLetters])
        ans = 0
        for word in text.split(" "):
            success = True
            for c in word:
                if c in st:
                    success = False
                    break
            if success:
                ans += 1
        return ans


text = input()
brokenLetters = input()


sol = Solution()
print(sol.canBeTypedWords(text, brokenLetters))
