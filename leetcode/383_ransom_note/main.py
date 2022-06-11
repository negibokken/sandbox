#!/usr/bin/python3

from typing import List
import json
from bplib.butil import TreeNode, arr2TreeNode, btreeconnect, aprint
from collections import Counter


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mp1 = Counter(ransomNote)
        mp2 = Counter(magazine)
        for k, v in mp1.items():
            if not k in mp2 or mp2[k] < v:
                return False
        return True


ransomNote = json.loads(input())
magazine = json.loads(input())

sol = Solution()
print(sol.canConstruct(ransomNote, magazine))
