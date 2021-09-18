#!/usr/bin/python3

from typing import List
import json


class Trie:
    ch = [None] * 26

    def insert(self, s, i=0):
        if i + 1 == len(s):
            idx = ord(s[i]) - ord('a')
            self.ch[idx] = Trie()
            return True
        idx = ord(s[i]) - ord('a')
        return False if self.ch[idx] is None else self.ch[idx].insert(s, i + 1)


class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        res = ""
        for word in sorted(words, key=len):
            if trie.insert(word):
                if len(res) < len(word) or word < res:
                    res = word
        return res


arr = json.loads(input())

sol = Solution()
print(sol.longestWord(arr))
