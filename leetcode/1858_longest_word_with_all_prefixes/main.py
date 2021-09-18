#!/usr/bin/python3

from typing import List
import json


class Solution:
    def longestWord(self, words: List[str]) -> str:
        d = set()
        d.add("")
        res = ""
        for word in sorted(words, key=len):
            if word[:-1] in d:
                d.add(word)
                if len(res) < len(word) or word < res:
                    res = word
        return res


arr = json.loads(input())

sol = Solution()
print(sol.longestWord(arr))
