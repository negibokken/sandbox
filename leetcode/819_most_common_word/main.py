#!/usr/bin/python3

from typing import List
import json
import re


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        st = set()
        for b in banned:
            st.add(b.lower())
        mp = {}
        for w in re.sub("[.,!@#\"'&$%`()*+/:;<=>?@]", " ", paragraph).replace("  ", " ").split(" "):
            w = w.lower()
            if w in st:
                continue
            if w not in mp:
                mp[w] = 0
            mp[w] += 1
        ans, mx = "", 0
        for k, v in mp.items():
            if v > mx:
                ans = k
                mx = v
        return ans


paragraph = input()
baned = json.loads(input())

sol = Solution()
print(sol.mostCommonWord(paragraph, baned))
